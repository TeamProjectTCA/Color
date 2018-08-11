#include "NWManagerForServer.h"
#include "ClientToServerData.h"
#include "ServerToClientDataUdp.h"
#include "ServerToClientDataTcp.h"
#include "ProcessorForServer.h"
#include "ConnectorForServer.h"

NWManagerForServer::NWManagerForServer( ClientToServerDataConstPtr recvdata, ServerToClientDataUdpPtr senddata_udp, ServerToClientDataTcpPtr senddata_tcp, ProcessorForServerPtr processor, LogPtr log ) :
_recvdata( recvdata ),
_senddata_udp( senddata_udp ),
_senddata_tcp( senddata_tcp ),
_processor( processor ) {
	_connector = ConnectorForServerPtr( new ConnectorForServer( log ) );
}

NWManagerForServer::~NWManagerForServer( ) {
}

void NWManagerForServer::initialize( ) {
	_connector->initialize( );
}

void NWManagerForServer::update( ) {
	_connector->update( );

	ServerPtr server = Server::getTask( );
	server->sendUdp( _senddata_udp );
	if ( _processor->isGameOver( ) ) {
		server->sendTcp( _senddata_tcp );
	}
}

ConnectorForServerConstPtr NWManagerForServer::getConnectorPtr( ) const {
	return _connector;
}