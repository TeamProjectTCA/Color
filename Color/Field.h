#pragma once
#include "smart_ptr.h"
#include "Area.h"
#include "FieldProperty.h"
#include <array>

PTR( Field );
PTR( Tile );

class Field : public Area {
public:
	Field( const Vector ORIGIN_POS );
	virtual ~Field( );

public:
	Vector getCenterPos( ) const;
	Vector getTilePos( int x, int y ) const;
	const int getTileSize( ) const;

private:
	std::array< std::array< TilePtr, FieldProperty::FIELD_COL >, FieldProperty::FIELD_ROW > _tile;
};

