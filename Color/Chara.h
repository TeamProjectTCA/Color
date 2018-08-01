#pragma once
#include "smart_ptr.h"
#include "Vector.h"

PTR( Chara );
PTR( Field );

class Chara {
public:
	Chara( FieldConstPtr field );
	virtual ~Chara( );

public:
	void setPos( Vector pos );

public:
	Vector getPos( ) const;

private:
	Vector _pos;
	FieldConstPtr _field;
};

