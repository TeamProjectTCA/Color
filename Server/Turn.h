#pragma once
#include "smart_ptr.h"
#include "Vector.h"
#include <array>

PTR( Player );

class Turn {
public:
	Turn( const std::array< PlayerPtr, 2 > &player );
	virtual ~Turn( );

public:
	void update( );

public:
	void countTurn( );

public:
	int getTurn( ) const;
	int getActivePlayer( ) const;

public:
	static const int TURN_MAX = 40;

private:
	int _turn;
	int _active_player;
	std::array< PlayerConstPtr, 2 > _player;
	std::array< Vector, 2 > _past_pos;
};

