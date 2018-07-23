#pragma once
#include "smart_ptr.h"

PTR( NWManagerForServer );
PTR( ClientToServerData );
PTR( ServerToClientDataUdp );
PTR( ProcessorForServer );

class NWManagerForServer {
public:
	NWManagerForServer( ClientToServerDataConstPtr recvdata, ServerToClientDataUdpPtr senddata_udp, ProcessorForServerPtr processor );
	virtual ~NWManagerForServer( );

private:
	ClientToServerDataConstPtr _recvdata;
	ServerToClientDataUdpPtr _senddata_udp;
	ProcessorForServerPtr _processor;
};

