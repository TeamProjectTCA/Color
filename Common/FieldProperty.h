#pragma once
#include "smart_ptr.h"
#include "Vector.h"

PTR( FieldProperty );

class FieldProperty {
public:
	static const int FIELD_COL = 6;
	static const int FIELD_ROW = 6;

public:
	enum TILE_STATE {
		TILE_STATE_NONE,
		TILE_STATE_PLAYER0,
		TILE_STATE_PLAYER1
	};

public:
	FieldProperty( );
	virtual ~FieldProperty( );

public:
	static Vector getPlayerInitPos( int player_idx );
};

