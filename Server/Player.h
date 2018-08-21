#pragma once
#include "smart_ptr.h"
#include "Vector.h"

PTR( Player );
PTR( Sheet );
PTR( ServerToClientDataUdp );
PTR( BattleField );

class Player {
public:
	Player( const int PLAYER_IDX, BattleFieldConstPtr field );
	virtual ~Player( );

public:
	void update( );

private:
	void updateSheet( );

public:
	void package( ServerToClientDataUdpPtr senddata );

public:
	Vector getPos( ) const;
	SheetPtr getSheet( ) const;

private:
	const int _PLAYER_IDX;
	Vector _pos;

	SheetPtr _sheet;
	BattleFieldConstPtr _field;
};

