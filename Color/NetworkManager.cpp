#include "NetworkManager.h"
#include "Manager.h"
#include "Connector.h"
#include "Client.h"

NetworkManager::NetworkManager( ServerToClientDataUdpConstPtr recvdata_udp, GameProcessorPtr processor ) :
_recvdata_udp( recvdata_udp ),
_game_processor( processor ) {
	_connector = ConnectorPtr( new Connector( ) );
	ClientPtr client = Client::getTask( );
	client->setConnectFlag( true );
}

NetworkManager::~NetworkManager( ) {
}

void NetworkManager::update( ) {
	_connector->update( );
}