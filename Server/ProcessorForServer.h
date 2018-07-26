#pragma once
#include "smart_ptr.h"

PTR( ProcessorForServer );
PTR( ServerToClientDataUdp );
PTR( Log );
PTR( Command );

class ProcessorForServer {
public:
	ProcessorForServer( ServerToClientDataUdpPtr senddata_udp, LogPtr log, CommandPtr command );
	virtual ~ProcessorForServer( );

public:
	void update( );

private:
	ServerToClientDataUdpPtr _senddata_udp;
	CommandPtr _command;
};

