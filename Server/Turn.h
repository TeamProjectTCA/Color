#pragma once
#include "smart_ptr.h"

PTR( Turn );

class Turn {
public:
	Turn( );
	virtual ~Turn( );

public:
	void update( );

public:
	int getTurn( ) const;
	const int getTURNMAX( ) const;

public:
	void countTurn( );

private:
	int _turn;
};

