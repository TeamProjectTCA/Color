#pragma once
#include "smart_ptr.h"
#include "Vector.h"
#include <array>
#include <vector>

PTR( Player );
PTR( Sheet );
PTR( ServerToClientDataUdp );
PTR( Players );

class Turn {
public:
	Turn( PlayersConstPtr players );
	virtual ~Turn( );

public:
	void update( );

private:
	void updateSheet( );
	void countTurn( );

public:
	void package( ServerToClientDataUdpPtr senddata );

public:
	SheetPtr getSheet( ) const;

public:
	static const int TURN_MAX = 40;

private:
	const int _PLAYER_NUM;

private:
	std::vector< bool > _move;
	int _turn;
	SheetPtr _sheet;
	PlayersConstPtr _players;
};

