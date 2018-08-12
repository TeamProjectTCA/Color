#pragma once
#include "smart_ptr.h"
#include "vector.h"

PTR( Field );
PTR( Chara );
PTR( User );

class Move {
public:
	Move( FieldConstPtr field, UserPtr user );
	virtual ~Move( );

public:
	void update( );

public:
	void sendClickMas( );

private:
	FieldConstPtr _field;
	UserPtr _user;
};

