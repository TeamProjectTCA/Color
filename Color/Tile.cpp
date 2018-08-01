#include "Tile.h"

Tile::Tile( Vector pos ) :
_state( TILE_STATE_NONE ),
_pos( pos ) {
}

Tile::~Tile( ) {
}

Tile::TILE_STATE Tile::getState( ) const {
	return _state;
}

Vector Tile::getPos( ) const {
	return _pos;
}
