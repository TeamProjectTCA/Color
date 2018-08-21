#include "BattleField.h"
#include "Sheet.h"
#include "ServerToClientDataUdp.h"

const int SHEET_ROW = 3;
const int SHEET_TAG_PITCH = 100;
const int SHEET_VALUE_PITCH = 200;

BattleField::BattleField( ) {
	std::array< std::array< Tile, FieldProperty::FIELD_COL >, FieldProperty::FIELD_ROW >( ).swap( _field );

	FieldPropertyPtr field_property( new FieldProperty );
	for ( int i = 0; i < PLAYER_NUM; i++ ) {
		_player_pos[ i ] = field_property->getPlayerInitPos( i );
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

void BattleField::updateSheet( ) {
	for ( int i = 0; i < PLAYER_NUM; i++ ) {
		_sheet->write( 1, 1 + i, std::to_string( getPaintCount( i ) ) );
	}
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
	FieldProperty::TILE_STATE state;
	if ( player_idx == 0 ) {
		state = FieldProperty::TILE_STATE_PLAYER0;
	}
	if ( player_idx == 1 ) {
		state = FieldProperty::TILE_STATE_PLAYER1;
	}

	_field[ y ][ x ].state = state;

	Vector pos = Vector( x, y );
	_player_pos[ player_idx ] = pos;
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

Vector BattleField::getPlayerPos( int player_idx ) const {
	return _player_pos[ player_idx ];
}

FieldProperty::TILE_STATE BattleField::getTileState( int x, int y ) const {
	return _field[ y ][ x ].state;
}

SheetPtr BattleField::getSheet( ) const {
	return _sheet;
}