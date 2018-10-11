#include "Game.h"
#include "GameProcessor.h"
#include "NetworkManager.h"
#include "ServerToClientDataUdp.h"

Game::Game( ServerToClientDataTcpConstPtr recvdata_tcp, ServerToClientDataUdpConstPtr recvdata_udp ) {
	_process  = GameProcessorPtr        ( new GameProcessor( ) );
	_network  = NetworkManagerPtr       ( new NetworkManager( recvdata_tcp, recvdata_udp, _process ) );
}

Game::~Game( ) {
}

void Game::update( ) {
	_process->update( );
	_network->update( );
}

void Game::draw( ) const {
}