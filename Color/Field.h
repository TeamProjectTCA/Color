#pragma once
#include "smart_ptr.h"
#include "Area.h"
#include <array>

PTR( Field );
PTR( Tile );

class Field : public Area {
public:
	static const int FIELD_COL = 6;
	static const int FIELD_ROW = 6;

public:
	Field( const Vector ORIGIN_POS );
	virtual ~Field( );

public:
	Vector getCenterPos( ) const;
	Vector getTilePos( int x, int y ) const;

private:
	std::array< std::array< TilePtr, FIELD_COL >, FIELD_ROW > _tile;
};

