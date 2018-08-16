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
	void setTile( Vector pos, int player_num );

public:
	int getPaintCount( int player_num ) const;

public:
	FieldProperty::TILE_STATE getState( int x, int y ) const;

private:
	std::array< std::array< FieldProperty::TILE_STATE, FieldProperty::FIELD_COL >, FieldProperty::FIELD_ROW > _state;
};
