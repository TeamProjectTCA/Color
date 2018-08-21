#include "BattleField.h"
#include "Sheet.h"
#include "ServerToClientDataUdp.h"
#include "CommandWord.h"
#include "Log.h"

const int SHEET_ROW = 3;
const int SHEET_TAG_PITCH = 100;
const int SHEET_VALUE_PITCH = 200;

BattleField::BattleField( LogPtr log ) :
_log( log ),
_click_idx( ) {
	std::array< std::array< Tile, FieldProperty::FIELD_COL >, FieldProperty::FIELD_ROW >( ).swap( _field );

	for ( int i = 0; i < PLAYER_NUM; i++ ) {
		_players_pos[ i ] = FieldProperty::getPlayerInitPos( i );
	}

	_sheet = SheetPtr( new Sheet( SHEET_ROW ) );
	_sheet->addCol( SHEET_TAG_PITCH );
	_sheet->addCol( SHEET_VALUE_PITCH );
	_sheet->write( 0, 0, "PLAYER" );
	_sheet->write( 0, 1, "0" );
	_sheet->write( 0, 2, "1" );
	_sheet->write( 1, 0, "PAINTCOUNT" );

	updateSheet( );
}

BattleField::~BattleField( ) {
}

void BattleField::update( ) {
	resetAct( );
}

void BattleField::updateSheet( ) {
	for ( int i = 0; i < PLAYER_NUM; i++ ) {
		_sheet->write( 1, 1 + i, std::to_string( getPaintCount( i ) ) );
	}
}

void BattleField::resetAct( ) {

}

bool BattleField::respawn( int x, int y, int player_idx ) {
	// リスポーンするかどうか
	int respawn_idx = -1;
	for ( int i = 0; i < PLAYER_NUM; i++ ) {
		Vector pos = _players_pos[ i ];
		int enemy_x = ( int )pos.x;
		int enemy_y = ( int )pos.y;

		// リスポーンする
		if ( enemy_x == x && enemy_y == y ) {
			int my_count = getPaintCount( player_idx );
			int enemy_count = getPaintCount( i );

			// 同数なら仕掛けたほうがリスポーン
			if ( my_count == enemy_count ) {
				respawn_idx = player_idx;
				break;
			}

			if ( my_count > enemy_count ) {
				respawn_idx = player_idx;
			} else {
				respawn_idx = i;
			}
			break;
		}
	}

	// リスポーン処理なしを返す
	if ( respawn_idx == -1 ) {
		return false;
	}

	Vector init_pos = FieldProperty::getPlayerInitPos( respawn_idx );
	if ( respawn_idx == player_idx ) {
		_players_pos[ respawn_idx ] = init_pos;
	} else {
		_players_pos[ player_idx ] = Vector( x, y );
		_players_pos[ respawn_idx ] = init_pos;
	}

	// リスポーン処理ありを返す
	return true;
}

void BattleField::package( ServerToClientDataUdpPtr senddata ) {
	for ( int i = 0; i < PLAYER_NUM; i++ ) {
		senddata->setPaintCount( i, getPaintCount( i ) );
	}

	for ( int y = 0; y < FieldProperty::FIELD_ROW; y++ ) {
		for ( int x = 0; x < FieldProperty::FIELD_COL; x++ ) {
			senddata->setTileState( x, y, _field[ y ][ x ].state );
		}
	}
}

void BattleField::setPlayerPos( int x, int y, int player_idx ) {
	_click_idx = Vector( x, y );

	FieldProperty::TILE_STATE state;
	if ( player_idx == 0 ) {
		state = FieldProperty::TILE_STATE_PLAYER0;
	}
	if ( player_idx == 1 ) {
		state = FieldProperty::TILE_STATE_PLAYER1;
	}

	bool is_respawn = respawn( x, y, player_idx );

	// リスポーン処理なし
	if ( !is_respawn ) {
		_field[ y ][ x ].state = state;

		Vector pos = Vector( x, y );
		_players_pos[ player_idx ] = pos;
	}
}

int BattleField::getPaintCount( int player_idx ) const {
	FieldProperty::TILE_STATE player = FieldProperty::TILE_STATE( );
	if ( player_idx == 0 ) {
		player = FieldProperty::TILE_STATE_PLAYER0;
	}
	if ( player_idx == 1 ) {
		player = FieldProperty::TILE_STATE_PLAYER1;
	}

	int count = 0;
	for ( int i = 0; i < FieldProperty::FIELD_ROW; i++ ) {
		for ( int j = 0; j < FieldProperty::FIELD_COL; j++ ) {
			if ( _field[ i ][ j ].state == player ) {
				count++;
			}
		}
	}
	return count;
}

Vector BattleField::getClickIdx( ) const {
	return _click_idx;
}

Vector BattleField::getPlayerPos( int player_idx ) const {
	return _players_pos[ player_idx ];
}

FieldProperty::TILE_STATE BattleField::getTileState( int x, int y ) const {
	return _field[ y ][ x ].state;
}

SheetPtr BattleField::getSheet( ) const {
	return _sheet;
}

CommandListener::RESULT BattleField::command( CommandWordConstPtr word ) {
	if ( word->getTokenCount( ) < 5 ) {
		return RESULT_THROW;
	}

	if ( word->getTokenString( 0 ) != "player" ) {
		return RESULT_THROW;
	}

	int player_idx = word->getTokenValue( 1 );
	if ( player_idx >= PLAYER_NUM || player_idx < 0 ) {
		addErrorLog( word->makeError( 1, " [ " + std::to_string( player_idx ) + " ] is out of range" ) );
		return RESULT_ERROR;
	}

	std::string word2 = word->getTokenString( 2 );
	if ( word2 != "move" ) {
		addErrorLog( word->makeError( 2, " [ " + word2 + " ] is spell miss" ) );
		return RESULT_ERROR;
	}

	int x = word->getTokenValue( 3 );
	int y = word->getTokenValue( 4 );
	if ( x >= FieldProperty::FIELD_COL ) {
		addErrorLog( word->makeError( 3, " [ " + std::to_string( x ) + " ] is out of range" ) );
		return RESULT_ERROR;
	} 
	if ( y >= FieldProperty::FIELD_ROW ) {
		addErrorLog( word->makeError( 4, " [ " + std::to_string( y ) + " ] is out of range" ) );
		return RESULT_ERROR;
	}

	setPlayerPos( x, y, player_idx );
	_log->add( "player " + std::to_string( player_idx ) + " move " + std::to_string( x ) + ", " + std::to_string( y ) );
	return RESULT_DONE;
}
