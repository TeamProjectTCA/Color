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
	void setColor( std::array< std::array< int, FieldProperty::FIELD_COL >, FieldProperty::FIELD_ROW > color );

public:
	Vector getCenterPos( ) const;
	Vector getTilePos( int x, int y ) const;
	const int getTileSize( ) const;

private:
	std::array< std::array< TilePtr, FieldProperty::FIELD_COL >, FieldProperty::FIELD_ROW > _tile;
	std::array< std::array< int,     FieldProperty::FIELD_COL >, FieldProperty::FIELD_ROW > _color;
	ImagePtr _base_tile;
	ImagePtr _red_tile;
	ImagePtr _blue_tile;
};

