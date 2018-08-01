#include "Game.h"
#include "GameProcessor.h"
#include "GameViewer.h"
#include "NetworkManager.h"
#include "ServerToClientDataUdp.h"

Game::Game( ServerToClientDataUdpConstPtr recvdata ) :
_recvdata( recvdata ) {
	_process  = GameProcessorPtr        ( new GameProcessor( ) );
	_viewer   = GameViewerPtr           ( new GameViewer( _process ) );
	_network  = NetworkManagerPtr       ( new NetworkManager( _recvdata, _process ) );
}

Game::~Game( ) {
}

void Game::update( ) {
	_process->update( );
	_viewer->update( );
	_network->update( );
}