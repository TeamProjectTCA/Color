#pragma once
#include "smart_ptr.h"

PTR( NetworkManager );
PTR( ServerToClientDataUdp );
PTR( Connector );
PTR( GameProcessor );

class NetworkManager {

public:
	NetworkManager( ServerToClientDataUdpConstPtr recvdata_udp, GameProcessorPtr game_processor );
	virtual ~NetworkManager( );

public:
	void finalize( );

public:
	void update( );

private:
	ServerToClientDataUdpConstPtr _recvdata_udp;
	ConnectorPtr                  _connector;
	GameProcessorPtr              _game_processor;
};

