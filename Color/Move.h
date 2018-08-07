#pragma once
#include "smart_ptr.h"
#include "vector.h"

PTR( Field );
PTR( Chara );

class Move {
public:
	Move( FieldConstPtr field, CharaPtr chara );
	virtual ~Move( );

private:
	Vector getClickMas( );

private:
	const int TILE_SIZE;
	const Vector START_POS;

	FieldConstPtr _field;
	CharaPtr _chara;
};

