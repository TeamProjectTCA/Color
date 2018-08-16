#include "PaintTile.h"

PaintTile::PaintTile( ) {
	std::array< std::array< FieldProperty::TILE_STATE, FieldProperty::FIELD_COL >, FieldProperty::FIELD_ROW >( ).swap( _state );
}

PaintTile::~PaintTile( ) {
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

FieldProperty::TILE_STATE PaintTile::getState( int x, int y ) const {
	return _state[ y ][ x ];
}
