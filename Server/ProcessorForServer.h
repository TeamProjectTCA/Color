#pragma once
#include "smart_ptr.h"
#include "Vector.h"

PTR( ProcessorForServer );
PTR( ServerToClientDataUdp );
PTR( ClientToServerData );
PTR( Log );
PTR( Command );
PTR( Player );

class ProcessorForServer {
public:
	ProcessorForServer( ClientToServerDataConstPtr recv_data,  ServerToClientDataUdpPtr senddata_udp, LogPtr log, CommandPtr command );
	virtual ~ProcessorForServer( );

public:
	void update( );

private:
	void packageData( );
	

public:
	PlayerConstPtr getPlayer0Ptr( ) const;
	PlayerConstPtr getPlayer1Ptr( ) const;

private:
	Vector _player0_init_pos;
	Vector _player1_init_pos;

	ServerToClientDataUdpPtr _senddata_udp;
	ClientToServerDataConstPtr _recv_data;
	CommandPtr _command;
	PlayerPtr _player0;
	PlayerPtr _player1;
};

