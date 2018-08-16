#pragma once
#include "smart_ptr.h"
#include "Vector.h"
#include <array>

PTR( ProcessorForServer );
PTR( ServerToClientDataUdp );
PTR( Log );
PTR( Command );
PTR( Player );
PTR( Turn );
PTR( PaintTile );

class ProcessorForServer {
public:
	ProcessorForServer( ServerToClientDataUdpPtr senddata_udp, LogPtr log, CommandPtr command );
	virtual ~ProcessorForServer( );

public:
	void update( );

public:
	void setPlayerPos( int player_num, Vector pos );
	void setTileColor( int player_num, Vector pos );

private:
	void packageDataUdp( );
	
public:
	PlayerConstPtr getPlayer0Ptr( ) const;
	PlayerConstPtr getPlayer1Ptr( ) const;
	TurnConstPtr getTurnPtr( ) const;
	PaintTileConstPtr getPaintPtr( ) const;

private:
	ServerToClientDataUdpPtr _senddata_udp;
	CommandPtr _command;
	TurnPtr _turn;
	PaintTilePtr _paint;
	std::array< PlayerPtr, 2 > _player;
};

