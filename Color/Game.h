#pragma once
#include "Scene.h"
#include "smart_ptr.h"

PTR( Game );
PTR( GameProcessor );
PTR( GameViewer );
PTR( NetworkManager );
PTR( ServerToClientDataUdp );

class Game : public Scene {
public:
	Game( ServerToClientDataUdpConstPtr recvdata );
	virtual ~Game( );

public:
	void update( );

private:
	GameProcessorPtr _process;
	GameViewerPtr _viewer;
	NetworkManagerPtr _network;
	ServerToClientDataUdpConstPtr _recvdata;
};