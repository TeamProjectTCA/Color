#include "NetworkManager.h"
#include "Manager.h"
#include "Connector.h"

NetworkManager::NetworkManager( ServerToClientDataUdpConstPtr recvdata_udp, GameProcessorPtr processor ) :
_recvdata_udp( recvdata_udp ),
_game_processor( processor ) {
	_connector = ConnectorPtr( new Connector( ) );
}

NetworkManager::~NetworkManager( ) {
}

void NetworkManager::initialize( ) {
	_connector->initialize( );
}

void NetworkManager::update( ) {
	_connector->update( );
}