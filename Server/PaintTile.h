#pragma once
#include "smart_ptr.h"
#include "FieldProperty.h"
#include <array>

PTR( PaintTile );
PTR( Sheet );
PTR( ServerToClientDataUdp );

class PaintTile {
public:
	PaintTile( );
	virtual ~PaintTile( );

private:
	void updateSheet( );

public:
	void setTile( Vector pos, int player_num );
	void package( ServerToClientDataUdpPtr senddata );

public:
	int getPaintCount( int player_num ) const;
	SheetPtr getSheet( ) const;

private:
	static const int PLAYER_NUM = 2;

private:
	std::array< std::array< FieldProperty::TILE_STATE, FieldProperty::FIELD_COL >, FieldProperty::FIELD_ROW > _state;
	SheetPtr _sheet;
};
