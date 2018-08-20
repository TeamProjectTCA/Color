#pragma once
#include "smart_ptr.h"
#include "Vector.h"

PTR( Player );
PTR( Sheet );
PTR( ServerToClientDataUdp );

class Player {
public:
	Player( const int PLAYER_IDX );
	virtual ~Player( );

private:
	void updateSheet( );

public:
	void package( ServerToClientDataUdpPtr senddata );
	void setPos( Vector pos );

public:
	Vector getPos( ) const;
	SheetPtr getSheet( ) const;

private:
	const int _PLAYER_IDX;
	Vector _pos;

	SheetPtr _sheet;
};

