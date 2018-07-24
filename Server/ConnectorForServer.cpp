#include "ConnectorForServer.h"
#include "Log.h"

ConnectorForServer::ConnectorForServer( LogPtr log ) :
_log( log ) {
	std::array< std::string, Server::MAX_MACHINES >( ).swap( _machines );
}

ConnectorForServer::~ConnectorForServer( ) {
}

void ConnectorForServer::initialize( ) {
	ServerPtr server = Server::getTask( );
	server->createIP( );
}

void ConnectorForServer::update( ) {
	checkConnect( );
}

std::string ConnectorForServer::getMachinesIp( int idx ) const {
	return _machines[ idx ];
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
			_log->add( "NEW CONNECT " + _machines[ i ] );
		}
	}
}