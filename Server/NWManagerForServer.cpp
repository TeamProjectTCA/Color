#include "NWManagerForServer.h"
#include "ClientToServerData.h"
#include "ServerToClientDataUdp.h"
#include "ProcessorForServer.h"
#include "ConnectorForServer.h"
#include "Server.h"

NWManagerForServer::NWManagerForServer( ClientToServerDataConstPtr recvdata, ServerToClientDataUdpPtr senddata_udp, ProcessorForServerPtr processor, LogPtr log ) :
_recvdata( recvdata ),
_senddata_udp( senddata_udp ),
_processor( processor ) {
	_connector = ConnectorForServerPtr( new ConnectorForServer( log ) );
}

NWManagerForServer::~NWManagerForServer( ) {
}

void NWManagerForServer::update( ) {
	_connector->update( );

	recv( );
	sendUdp( );
}

void NWManagerForServer::sendUdp( ) {
	ServerPtr server = Server::getTask( );
	server->sendUdp( _senddata_udp );
}

void NWManagerForServer::recv( ) {
	ServerPtr server = Server::getTask( );
	if ( server->getRecievingIdx( ) == -1 ) {
		return;
	}

	switch ( _recvdata->getDataType( ) ) {
	case ClientToServerData::DATA_TYPE_PLAYER:
		recvPlayerPos( );
		break;
	}
}

void NWManagerForServer::recvPlayerPos( ) {
	int player_num = _recvdata->getPlayerNum( );
	_processor->setPlayerPos( player_num, _recvdata->getClickMas( ) );
}

ConnectorForServerConstPtr NWManagerForServer::getConnectorPtr( ) const {
	return _connector;
}