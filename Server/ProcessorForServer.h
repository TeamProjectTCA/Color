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
PTR( Table );
PTR( NWManagerForServer );
PTR( ClientToServerData );

class ProcessorForServer {
public:
	ProcessorForServer( ServerToClientDataUdpPtr senddata_udp, NWManagerForServerConstPtr network, LogPtr log, CommandPtr command, TablePtr viewer );
	virtual ~ProcessorForServer( );

public:
	void update( );

private:
	void packageDataUdp( );
	void recv( );
	void recvPlayer( ClientToServerDataConstPtr data );

private:
	static const int PLAYER_NUM = 2;

private:
	ServerToClientDataUdpPtr _senddata_udp;
	CommandPtr _command;
	TurnPtr _turn;
	PaintTilePtr _paint;
	std::array< PlayerPtr, PLAYER_NUM > _player;

	NWManagerForServerConstPtr _network;
};

