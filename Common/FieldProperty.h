#pragma once
#include "smart_ptr.h"
#include "Vector.h"

PTR( FieldProperty );

class FieldProperty {
public:
	static const int FIELD_COL = 6;
	static const int FIELD_ROW = 6;

public:
	FieldProperty( );
	virtual ~FieldProperty( );

public:
	Vector getPlayer0InitPos( ) const;
	Vector getPlayer1InitPos( ) const;
};

