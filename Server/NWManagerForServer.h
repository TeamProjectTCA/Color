#pragma once
#include "smart_ptr.h"

PTR( NWManagerForServer );
PTR( ClientToServerData );
PTR( ServerToClientDataUdp );
PTR( ProcessorForServer );
PTR( Log );
PTR( ConnectorForServer );

class NWManagerForServer {
public:
	NWManagerForServer( ClientToServerDataConstPtr recvdata, ServerToClientDataUdpPtr senddata_udp, ProcessorForServerPtr processor, LogPtr log );
	virtual ~NWManagerForServer( );

public:
	void initialize( );
	void update( );

public:
	ConnectorForServerConstPtr getConnectorPtr( ) const;

private:
	ClientToServerDataConstPtr _recvdata;
	ServerToClientDataUdpPtr _senddata_udp;
	ProcessorForServerPtr _processor;
	ConnectorForServerPtr _connector;
};
