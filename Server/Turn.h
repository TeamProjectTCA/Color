#pragma once
#include "smart_ptr.h"
#include "Vector.h"
#include <array>

PTR( Player );
PTR( Sheet );
PTR( ServerToClientDataUdp );

class Turn {
private:
	static const int PLAYER_NUM = 2;

public:
	Turn( const std::array< PlayerPtr, PLAYER_NUM > &player );
	virtual ~Turn( );

public:
	void update( );

private:
	void updateSheet( );
	void countTurn( );

public:
	void package( ServerToClientDataUdpPtr senddata );

public:
	int getActivePlayer( ) const;
	SheetPtr getSheet( ) const;

public:
	static const int TURN_MAX = 40;

private:
	int _turn;
	int _active_player;
	std::array< PlayerConstPtr, 2 > _player;
	std::array< Vector, 2 > _past_pos;
	SheetPtr _sheet;
};

