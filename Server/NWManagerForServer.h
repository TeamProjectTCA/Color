#pragma once
#include "smart_ptr.h"

PTR( NWManagerForServer );
PTR( ClientToServerData );
PTR( ServerToClientDataUdp );
PTR( ServerToClientDataTcp );
PTR( ProcessorForServer );
PTR( Log );
PTR( ConnectorForServer );

class NWManagerForServer {
public:
	NWManagerForServer( ClientToServerDataConstPtr recvdata, ServerToClientDataUdpPtr senddata_udp, ServerToClientDataTcpPtr senddata_tcp, ProcessorForServerPtr processor, LogPtr log );
	virtual ~NWManagerForServer( );

public:
	void initialize( );
	void update( );

public:
	ConnectorForServerConstPtr getConnectorPtr( ) const;

private:
	ClientToServerDataConstPtr _recvdata;
	ServerToClientDataUdpPtr _senddata_udp;
	ServerToClientDataTcpPtr _senddata_tcp;
	ProcessorForServerPtr _processor;
	ConnectorForServerPtr _connector;
};

