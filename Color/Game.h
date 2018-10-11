#pragma once
#include "Scene.h"
#include "smart_ptr.h"

PTR( Game );
PTR( GameProcessor );
PTR( NetworkManager );
PTR( ServerToClientDataUdp );
PTR( ServerToClientDataTcp );

class Game : public Scene {
public:
	Game( ServerToClientDataTcpConstPtr recvdata_tcp, ServerToClientDataUdpConstPtr recvdata_udp );
	virtual ~Game( );

public:
	void update( );
	void draw( ) const;

private:
	GameProcessorPtr _process;
	NetworkManagerPtr _network;
};