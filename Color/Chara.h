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
	virtual void update( );

public:
	void setFieldIdx( Vector pos );

public:
	Vector getFieldIdx( ) const;
	Vector getScreenPos( ) const;

private:
	Vector _pos;
	FieldConstPtr _field;
};

