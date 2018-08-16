#include "Game.h"
#include "GameProcessor.h"
#include "Viewer.h"
#include "NetworkManager.h"
#include "ServerToClientDataUdp.h"

Game::Game( ServerToClientDataTcpConstPtr recvdata_tcp, ServerToClientDataUdpConstPtr recvdata_udp, ViewerPtr viewer ) :
_recvdata_tcp( recvdata_tcp ),
_recvdata_udp( recvdata_udp ) {
	_process  = GameProcessorPtr        ( new GameProcessor( viewer ) );
	_network  = NetworkManagerPtr       ( new NetworkManager( _recvdata_tcp, _recvdata_udp, _process ) );
}

Game::~Game( ) {
}

void Game::update( ) {
	_process->update( );
	_network->update( );
}