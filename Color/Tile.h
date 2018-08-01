#pragma once
#include "smart_ptr.h"
#include "Vector.h"

PTR( Tile );

class Tile {
public:
	enum TILE_STATE {
		TILE_STATE_NONE,
		TILE_STATE_PLAYER1,
		TILE_STATE_PLAYER2,
		TILE_STATE_MAX
	};

public:
	Tile( Vector pos );
	virtual ~Tile( );

public:
	TILE_STATE getState( ) const;
	Vector getPos( ) const;

private:
	TILE_STATE _state;
	Vector _pos;
};

