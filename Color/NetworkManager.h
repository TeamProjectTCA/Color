#pragma once
#include "smart_ptr.h"

PTR( NetworkManager );
PTR( ServerToClientDataUdp );
PTR( Connector );
PTR( GameProcessor );

class NetworkManager {
public:
	NetworkManager( ServerToClientDataUdpConstPtr recvdata_udp, GameProcessorPtr processor );
	virtual ~NetworkManager( );

public:
	void update( );

private:
	void recv( );

private:
	ServerToClientDataUdpConstPtr _recvdata_udp;
	ConnectorPtr _connector;
	GameProcessorPtr _processor;
};

