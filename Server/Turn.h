#pragma once
#include "smart_ptr.h"

PTR( Turn );

class Turn {
public:
	Turn( );
	virtual ~Turn( );

public:
	void setTurn( int turn );

public:
	int getTurn( ) const;

public:
	void countTurn( );

public:
	static const int TURN_MAX = 40 * 2;

private:
	int _turn;
};

