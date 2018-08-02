#pragma once
#include "Scene.h"
#include "smart_ptr.h"

PTR( Game );
PTR( GameProcessor );
PTR( GameViewer );
PTR( NetworkManager );
PTR( ServerToClientDataUdp );
PTR( ServerToClientDataTcp );

class Game : public Scene {
public:
	Game( ServerToClientDataTcpConstPtr recvdata_tcp, ServerToClientDataUdpConstPtr recvdata_udp );
	virtual ~Game( );

public:
	void update( );

private:
	GameProcessorPtr _process;
	GameViewerPtr _viewer;
	NetworkManagerPtr _network;
	ServerToClientDataUdpConstPtr _recvdata_udp;
	ServerToClientDataTcpConstPtr _recvdata_tcp;
};