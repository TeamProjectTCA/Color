#pragma once
#include "smart_ptr.h"
#include "vector.h"

PTR( Field );
PTR( Chara );
PTR( User );

class Move {
public:
	Move( FieldConstPtr field, CharaPtr user );
	virtual ~Move( );

public:
	void update( );

public:
	Vector getClickMas( ) const;

private:
	FieldConstPtr _field;
	CharaPtr _user;
};

