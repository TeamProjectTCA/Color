#pragma once
#include "smart_ptr.h"
#include "FieldProperty.h"
#include <array>

PTR( Sheet );
PTR( ServerToClientDataUdp );

class BattleField {
private:
	struct Tile {
		FieldProperty::TILE_STATE state;
	};

public:
	BattleField( );
	virtual ~BattleField( );

private:
	void updateSheet( );

public:
	void package( ServerToClientDataUdpPtr senddata );
	void setPlayerPos( int x, int y, int player_idx );

private:
	int getPaintCount( int player_idx ) const;

public:
	Vector getPlayerPos( int player_idx ) const;
	FieldProperty::TILE_STATE getTileState( int x, int y ) const;

	SheetPtr getSheet( ) const;

private:
	const static int PLAYER_NUM = 2;

private:
	std::array< Vector, PLAYER_NUM > _player_pos;
	std::array< std::array< Tile, FieldProperty::FIELD_COL >, FieldProperty::FIELD_ROW > _field;

	SheetPtr _sheet;
};

