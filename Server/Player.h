#pragma once
#include "smart_ptr.h"
#include "Vector.h"

PTR( Player );

class Player {
public:
	Player( const int PLAYER_NUM, const Vector POS );
	virtual ~Player( );

public:
	void setPos( Vector pos );

public:
	const int getPlayerNum( ) const;
	Vector getPos( ) const;

private:
	const int _PLAYER_NUM;
	Vector _pos;
};

