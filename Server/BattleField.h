#pragma once
#include "smart_ptr.h"
#include "FieldProperty.h"
#include "CommandListener.h"
#include <array>

PTR( Sheet );
PTR( ServerToClientDataUdp );
PTR( CommandWord );
PTR( Log );

class BattleField : public CommandListener {
private:
	struct Tile {
		FieldProperty::TILE_STATE state;
	};

public:
	BattleField( LogPtr log );
	virtual ~BattleField( );

public:
	void update( );
	CommandListener::RESULT command( CommandWordConstPtr word );

private:
	void updateSheet( );
	void resetAct( );
	bool respawn( int x, int y, int player_idx );

public:
	void package( ServerToClientDataUdpPtr senddata );
	void setPlayerPos( int x, int y, int player_idx );

private:
	int getPaintCount( int player_idx ) const;

public:
	Vector getClickIdx( ) const;
	Vector getPlayerPos( int player_idx ) const;
	FieldProperty::TILE_STATE getTileState( int x, int y ) const;

	SheetPtr getSheet( ) const;

private:
	const static int PLAYER_NUM = 2;

private:
	Vector _click_idx;
	std::array< Vector, PLAYER_NUM > _players_pos;
	std::array< std::array< Tile, FieldProperty::FIELD_COL >, FieldProperty::FIELD_ROW > _field;

	LogPtr _log;
	SheetPtr _sheet;
};

