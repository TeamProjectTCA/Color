#include "Game.h"
#include "GameProcessor.h"
#include "GameViewer.h"
#include "NetworkManager.h"
#include "ServerToClientDataUdp.h"

Game::Game( ServerToClientDataTcpConstPtr recvdata_tcp, ServerToClientDataUdpConstPtr recvdata_udp ) :
_recvdata_tcp( recvdata_tcp ),
_recvdata_udp( recvdata_udp ) {
	_process  = GameProcessorPtr        ( new GameProcessor( ) );
	_viewer   = GameViewerPtr           ( new GameViewer( _process ) );
	_network  = NetworkManagerPtr       ( new NetworkManager( _recvdata_tcp, _recvdata_udp, _process ) );
}

Game::~Game( ) {
}

void Game::update( ) {
	_process->update( );
	_viewer->update( );
	_network->update( );
}