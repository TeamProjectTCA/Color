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
	Game( );
	~Game( );

public:
	void initialize( );
	void update( );

private:
	GameProcessorPtr         _process;
	GameViewerPtr            _viewer;
	NetworkManagerPtr        _network;
	ServerToClientDataUdpPtr _recvdata;
};