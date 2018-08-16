#pragma once
#include "smart_ptr.h"
#include "FieldProperty.h"
#include <array>

PTR( PaintTile );

class PaintTile {
public:
	PaintTile( );
	virtual ~PaintTile( );

public:
	void setTileColor( Vector pos, int player_num );

public:
	int getPaintCount( int player_num ) const;

public:
	std::array< std::array< int, FieldProperty::FIELD_COL >, FieldProperty::FIELD_ROW > getTileColor( ) const;

private:
	std::array< std::array< int, FieldProperty::FIELD_COL >, FieldProperty::FIELD_ROW > _color;
};
