#pragma once
#include "Vector.h"

class Area {
public:
	Area( const Vector ORIGIN_POS );
	virtual ~Area( );

public:
	virtual void draw( ) const { };
	Vector getOrigin( ) const;

private:
	Vector _origin;
};

