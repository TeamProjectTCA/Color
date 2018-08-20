#pragma once
#include "smart_ptr.h"

PTR( NWManagerForServer );
PTR( ClientToServerData );
PTR( ServerToClientDataUdp );
PTR( Log );
PTR( ConnectorForServer );
PTR( Table );

class NWManagerForServer {
public:
	NWManagerForServer( ClientToServerDataConstPtr recvdata, ServerToClientDataUdpPtr senddata_udp, LogPtr log, TablePtr viewer );
	virtual ~NWManagerForServer( );

public:
	void update( );

public:
	bool isRecieving( ) const;
	ClientToServerDataConstPtr getRecvData( ) const;

private:
	void sendUdp( );

private:
	ClientToServerDataConstPtr _recvdata;
	ServerToClientDataUdpPtr _senddata_udp;
	ConnectorForServerPtr _connector;
};

