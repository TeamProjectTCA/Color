#include "NetworkManager.h"
#include "Manager.h"
#include "Connector.h"
#include "Client.h"
#include "GameProcessor.h"
#include "ServerToClientDataUdp.h"
#include "ServerToClientDataTcp.h"
#include "ClientToServerData.h"

NetworkManager::NetworkManager( ServerToClientDataTcpConstPtr recvdata_tcp, ServerToClientDataUdpConstPtr recvdata_udp, GameProcessorPtr processor ) :
_recvdata_tcp( recvdata_tcp ),
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

	recvTcp( );
	recvUdp( );
}

void NetworkManager::recvUdp( ) {
	ClientPtr client = Client::getTask( );
	if ( !client->isRecievingUdp( ) ) {
		return;
	}

	std::string ip = client->getClientIP( );
	int idx = _recvdata_tcp->getIdx( ip );
	if ( idx == -1 ) {
		return;
	}

	_processor->setUserFieldIdx( _recvdata_udp->getPlayerPos( idx ) );
	_processor->setEnemyFieldIdx( _recvdata_udp->getPlayerPos( ( idx + 1 ) % 2 ) );
	_processor->setTurn( _recvdata_udp->getTurn( ) );
}

void NetworkManager::recvTcp( ) {
	ClientPtr client = Client::getTask( );
	if ( !client->isRecievingTcp( ) ) {
		return;
	}

	unsigned char type = _recvdata_tcp->getType( );
	switch ( type ) {
	case ServerToClientDataTcp::DATA_TYPE_PLAYER:
	{
		std::string ip = client->getClientIP( );
		int idx = _recvdata_tcp->getIdx( ip );
		_processor->setPlayerNum( idx );
	}
		break;
	case ServerToClientDataTcp::DATA_TYPE_RESULT:
	{
		bool gameover = _recvdata_tcp->getGameOver( );
		_processor->setGameOver( gameover );
	}
	break;
	default:
		break;
	}

}