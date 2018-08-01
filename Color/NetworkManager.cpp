#include "NetworkManager.h"
#include "Manager.h"
#include "Connector.h"
#include "Client.h"
#include "GameProcessor.h"
#include "ServerToClientDataUdp.h"

NetworkManager::NetworkManager( ServerToClientDataUdpConstPtr recvdata_udp, GameProcessorPtr processor ) :
_recvdata_udp( recvdata_udp ),
_processor( processor ) {
	_connector = ConnectorPtr( new Connector( ) );
	ClientPtr client = Client::getTask( );
	client->setConnectFlag( true );
}

NetworkManager::~NetworkManager( ) {
}

void NetworkManager::update( ) {
	_connector->update( );

	recv( );
}

void NetworkManager::recv( ) {
	ClientPtr client = Client::getTask( );
	if ( !client->isRecievingUdp( ) ) {
		return;
	}

	_processor->setPlayer0Pos( _recvdata_udp->getPlayer0Pos( ) );
	_processor->setPlayer1Pos( _recvdata_udp->getPlayer1Pos( ) );
}