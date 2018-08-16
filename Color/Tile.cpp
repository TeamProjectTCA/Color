#include "Tile.h"

Tile::Tile( Vector pos ) :
_state( FieldProperty::TILE_STATE_NONE ),
_pos( pos ) {
}

Tile::~Tile( ) {
}

void Tile::setState( FieldProperty::TILE_STATE state ) {
	_state = state;
}

FieldProperty::TILE_STATE Tile::getState( ) const {
	return _state;
}

Vector Tile::getPos( ) const {
	return _pos;
}
