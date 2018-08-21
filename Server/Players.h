#pragma once
#include "smart_ptr.h"
#include <array>

PTR( Player );
PTR( BattleField );
PTR( Table );
PTR( ServerToClientDataUdp );

class Players {
public:
	Players( BattleFieldConstPtr field, TablePtr viewer );
	virtual ~Players( );

public:
	void update( );

public:
	void package( ServerToClientDataUdpPtr senddata );

public:
	int getPlayerNum( ) const;
	PlayerConstPtr getPlayer( int player_idx ) const;

private:
	static const int PLAYER_NUM = 2;

private:
	int _respawn_count;
	std::array< PlayerPtr, PLAYER_NUM > _players;
};

