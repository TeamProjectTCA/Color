#pragma once
#include "smart_ptr.h"
#include "Vector.h"
#include "GameDrawer.h"

PTR( Chara );
PTR( Field );

class Chara : public GameDrawer {
public:
	Chara( FieldConstPtr field );
	virtual ~Chara( );

public:
	virtual void update( );
	void draw( ) const;

public:
	void setFieldIdx( Vector pos );

public:
	Vector getFieldIdx( ) const;
	Vector getScreenPos( ) const;

private:
	Vector _pos;
	FieldConstPtr _field;
};

