#include "ConnectorForServer.h"
#include "ServerToClientDataTcp.h"
#include "Log.h"

ConnectorForServer::ConnectorForServer( LogPtr log ) :
_log( log ) {
	std::array< std::string, Server::MAX_MACHINES >( ).swap( _machines );
	ServerPtr server = Server::getTask( );
	server->createIP( );
}

ConnectorForServer::~ConnectorForServer( ) {
}

void ConnectorForServer::update( ) {
	checkConnect( );
}

std::string ConnectorForServer::getMachinesIp( int idx ) const {
	return _machines[ idx ];
}

std::string ConnectorForServer::getServerIp( ) const {
	ServerConstPtr server = Server::getTask( );
	return server->getServerIP( );
}

void ConnectorForServer::checkConnect( ) {
	ServerPtr server = Server::getTask( );
	for ( int i = 0; i < Server::MAX_MACHINES; i++ ) {
		std::string past_ip = _machines[ i ];

		_machines[ i ] = server->getClientIP( i );

		// lost connect
		if ( _machines[ i ] == "" && past_ip != "" ) {
			_log->add( "LOST " + past_ip );
		}

		// new connect
		if ( _machines[ i ] != "" && past_ip == "" ) {
			ServerToClientDataTcpPtr senddata_tcp( new ServerToClientDataTcp );
			senddata_tcp->setIP( i, _machines[ i ] );
			server->sendTcp( senddata_tcp );
			_log->add( "NEW CONNECT " + _machines[ i ] );
			
		}
	}
}