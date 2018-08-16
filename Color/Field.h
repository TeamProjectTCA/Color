#pragma once
#include "smart_ptr.h"
#include "Area.h"
#include "FieldProperty.h"
#include "GameDrawer.h"
#include <array>

PTR( Field );
PTR( Image );
PTR( Tile );

class Field : public Area, public GameDrawer {
public:
	Field( const Vector ORIGIN_POS );
	virtual ~Field( );

public:
	void draw( ) const;

public:
	void setTileState( int x, int y, FieldProperty::TILE_STATE state );

public:
	Vector getCenterPos( ) const;
	Vector getTilePos( int x, int y ) const;
	const int getTileSize( ) const;

private:
	std::array< std::array< TilePtr, FieldProperty::FIELD_COL >, FieldProperty::FIELD_ROW > _tile;
	std::array< std::array< int,     FieldProperty::FIELD_COL >, FieldProperty::FIELD_ROW > _color;
	int _base_tile;
	int _red_tile;
	int _blue_tile;
};

