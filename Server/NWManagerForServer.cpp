#include "NWManagerForServer.h"
#include "ClientToServerData.h"
#include "ServerToClientDataUdp.h"
#include "ProcessorForServer.h"
#include "ConnectorForServer.h"
#include "Server.h"
#include "Table.h"

NWManagerForServer::NWManagerForServer( ClientToServerDataConstPtr recvdata, ServerToClientDataUdpPtr senddata_udp, LogPtr log, TablePtr viewer ) :
_recvdata( recvdata ),
_senddata_udp( senddata_udp ) {
	_connector = ConnectorForServerPtr( new ConnectorForServer( log ) );

	viewer->add( _connector->getSheetServer( ) , Table::NEXT_POS_DOWN );
	viewer->add( _connector->getSheetClient( ) , Table::NEXT_POS_RIGHT );
}

NWManagerForServer::~NWManagerForServer( ) {
}

void NWManagerForServer::update( ) {
	_connector->update( );

	sendUdp( );
}

bool NWManagerForServer::isRecieving( ) const {
	ServerConstPtr server = Server::getTask( );
	return ( server->getRecievingIdx( ) != -1 );
}

ClientToServerDataConstPtr NWManagerForServer::getRecvData( ) const {
	return _recvdata;
}

void NWManagerForServer::sendUdp( ) {
	ServerPtr server = Server::getTask( );
	server->sendUdp( _senddata_udp );
}
