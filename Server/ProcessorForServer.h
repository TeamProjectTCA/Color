#pragma once
#include "smart_ptr.h"

PTR( ProcessorForServer );
PTR( ServerToClientDataUdp );
PTR( Log );
PTR( Command );
PTR( Player );

class ProcessorForServer {
public:
	ProcessorForServer( ServerToClientDataUdpPtr senddata_udp, LogPtr log, CommandPtr command );
	virtual ~ProcessorForServer( );

public:
	void update( );

private:
	void packageData( );
	

public:
	PlayerConstPtr getPlayer0Ptr( ) const;
	PlayerConstPtr getPlayer1Ptr( ) const;

private:
	ServerToClientDataUdpPtr _senddata_udp;
	CommandPtr _command;
	PlayerPtr _player0;
	PlayerPtr _player1;
};

