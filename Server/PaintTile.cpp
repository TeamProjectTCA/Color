#include "PaintTile.h"
#include "Sheet.h"
#include "ServerToClientDataUdp.h"

const int SHEET_ROW = 3;
const int SHEET_TAG_PITCH = 100;
const int SHEET_VALUE_PITCH = 200;

PaintTile::PaintTile( ) {
	std::array< std::array< FieldProperty::TILE_STATE, FieldProperty::FIELD_COL >, FieldProperty::FIELD_ROW >( ).swap( _state );
	_sheet = SheetPtr( new Sheet( SHEET_ROW ) );
	_sheet->addCol( SHEET_TAG_PITCH );
	_sheet->addCol( SHEET_VALUE_PITCH );
	_sheet->write( 0, 0, "PLAYER" );
	_sheet->write( 0, 1, "0" );
	_sheet->write( 0, 2, "1" );
	_sheet->write( 1, 0, "PAINTCOUNT" );

	updateSheet( );
}

PaintTile::~PaintTile( ) {
}

void PaintTile::updateSheet( ) {
	for ( int i = 0; i < PLAYER_NUM; i++ ) {
		_sheet->write( 1, 1 + i, std::to_string( getPaintCount( i ) ) );
	}
}

void PaintTile::setTile( Vector pos, int player_num ) {
	FieldProperty::TILE_STATE state = FieldProperty::TILE_STATE( );
	if ( player_num == 0 ) {
		state = FieldProperty::TILE_STATE_PLAYER0;
	}
	if ( player_num == 1 ) {
		state = FieldProperty::TILE_STATE_PLAYER1;
	}

	_state[ ( int )pos.y ][ ( int )pos.x ] = state;

	updateSheet( );
}

void PaintTile::package( ServerToClientDataUdpPtr senddata ) {
	for ( int i = 0; i < PLAYER_NUM; i++ ) {
		senddata->setPaintCount( i, getPaintCount( i ) );
	}

	for ( int y = 0; y < FieldProperty::FIELD_ROW; y++ ) {
		for ( int x = 0; x < FieldProperty::FIELD_COL; x++ ) {
			senddata->setTileState( x, y, _state[ y ][ x ] );
		}
	}
}

int PaintTile::getPaintCount( int player_num ) const {
	FieldProperty::TILE_STATE player = FieldProperty::TILE_STATE( );
	if ( player_num == 0 ) {
		player = FieldProperty::TILE_STATE_PLAYER0;
	}
	if ( player_num == 1 ) {
		player = FieldProperty::TILE_STATE_PLAYER1;
	}

	int count = 0;
	for ( int i = 0; i < FieldProperty::FIELD_ROW; i++ ) {
		for ( int j = 0; j < FieldProperty::FIELD_COL; j++ ) {
			if ( _state[ i ][ j ] == player ) {
				count++;
			}
		}
	}
	return count;
}

SheetPtr PaintTile::getSheet( ) const {
	return _sheet;
}