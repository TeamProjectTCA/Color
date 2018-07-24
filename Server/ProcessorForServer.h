#pragma once
#include "smart_ptr.h"

PTR( ProcessorForServer );
PTR( ServerToClientDataUdp );
PTR( Log );

class ProcessorForServer {
public:
	ProcessorForServer( ServerToClientDataUdpPtr senddata_udp, LogPtr log );
	virtual ~ProcessorForServer( );

private:
	ServerToClientDataUdpPtr _senddata_udp;
};

