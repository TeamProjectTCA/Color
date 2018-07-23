#pragma once
#include "smart_ptr.h"

PTR( ProcessorForServer );
PTR( ServerToClientDataUdp );

class ProcessorForServer {
public:
	ProcessorForServer( ServerToClientDataUdpPtr senddata_udp );
	virtual ~ProcessorForServer( );

private:
	ServerToClientDataUdpPtr _senddata_udp;
};

