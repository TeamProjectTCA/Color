#pragma once
#include "Vector.h"
#include "FieldProperty.h"

class Tile {
public:
	Tile( Vector pos );
	virtual ~Tile( );

public:
	void setState( FieldProperty::TILE_STATE state );

public:
	FieldProperty::TILE_STATE getState( ) const;
	Vector getPos( ) const;

private:
	FieldProperty::TILE_STATE _state;
	Vector _pos;
};

