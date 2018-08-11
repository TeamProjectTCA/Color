#pragma once
#include "smart_ptr.h"

PTR( NetworkManager );
PTR( ServerToClientDataUdp );
PTR( ServerToClientDataTcp );
PTR( ClientToServerData );
PTR( Connector );
PTR( GameProcessor );

class NetworkManager {
public:
	NetworkManager( ServerToClientDataTcpConstPtr recvdata_tcp, ServerToClientDataUdpConstPtr recvdata_udp, GameProcessorPtr processor );
	virtual ~NetworkManager( );

public:
	void update( );

private:
	void recvUdp( );
	void recvTcp( );
	void sendTcp( );

private:
	ServerToClientDataUdpConstPtr _recvdata_udp;
	ServerToClientDataTcpConstPtr _recvdata_tcp;
	ConnectorPtr _connector;
	GameProcessorPtr _processor;
};

