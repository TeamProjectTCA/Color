#pragma once
#include "smart_ptr.h"
#include "vector.h"

PTR( Field );
PTR( Chara );
PTR( User );

class Move {
public:
	Move( FieldConstPtr field, UserConstPtr user );
	virtual ~Move( );

public:
	void update( );

private:
	const int _TILE_SIZE;
	const Vector _START_POS;
	UserConstPtr _user;
};

