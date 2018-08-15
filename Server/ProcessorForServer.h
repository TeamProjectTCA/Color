#pragma once
#include "smart_ptr.h"
#include "Vector.h"
#include <array>

PTR( ProcessorForServer );
PTR( ServerToClientDataUdp );
PTR( ClientToServerData );
PTR( Log );
PTR( Command );
PTR( Player );
PTR( Turn );
PTR( PaintTile );

class ProcessorForServer {
public:
	ProcessorForServer( ClientToServerDataConstPtr recv_data,  ServerToClientDataUdpPtr senddata_udp, LogPtr log, CommandPtr command );
	virtual ~ProcessorForServer( );

public:
	void update( );

private:
	void packageData( );
	void playerMove( );
	void sendGameOver( );
	
public:
	PlayerConstPtr getPlayer0Ptr( ) const;
	PlayerConstPtr getPlayer1Ptr( ) const;
	TurnConstPtr getTurnPtr( ) const;

private:
	std::array< Vector, 2 > _player_init_pos;

	ServerToClientDataUdpPtr _senddata_udp;
	ClientToServerDataConstPtr _recv_data;
	CommandPtr _command;
	TurnPtr _turn;
	PaintTilePtr _paint;
	std::array< PlayerPtr, 2 > _player;
};

