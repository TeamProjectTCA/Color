#include "ConnectorForServer.h"
#include "ServerToClientDataTcp.h"
#include "Log.h"
#include "Sheet.h"

const short int ROW_NUM = Server::MAX_MACHINES + 1;
const short int TAG_PITCH_ID = 100;
const short int TAG_PITCH_IP = 150;

ConnectorForServer::ConnectorForServer( LogPtr log ) :
_log( log ) {
	std::array< std::string, Server::MAX_MACHINES >( ).swap( _machines );
	ServerPtr server = Server::getTask( );
	server->createIP( );

	_sheet_server = SheetPtr( new Sheet( 1 ) );
	_sheet_server->addCol( TAG_PITCH_ID );
	_sheet_server->addCol( TAG_PITCH_IP );
	_sheet_server->write( 0, 0, "SERVER IP" );
	_sheet_server->write( 1, 0, server->getServerIP( ) );

	_sheet_client = SheetPtr( new Sheet( ROW_NUM ) );
	_sheet_client->addCol( TAG_PITCH_ID );
	_sheet_client->addCol( TAG_PITCH_IP );
	_sheet_client->write( 0, 0, "CLIENT ID" );
	_sheet_client->write( 1, 0, "CLIENT IP" );

	updateSheet( );
}

ConnectorForServer::~ConnectorForServer( ) {
}

void ConnectorForServer::update( ) {
	checkConnect( );
}

void ConnectorForServer::updateSheet( ) {
	ServerConstPtr server = Server::getTask( );

	for ( int i = 0; i < Server::MAX_MACHINES; i++ ) {
		_sheet_client->write( 0, i + 1, std::to_string( i ) );
		_sheet_client->write( 1, i + 1, server->getClientIP( i ) );
	}
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

			updateSheet( );
		}

		// new connect
		if ( _machines[ i ] != "" && past_ip == "" ) {
			ServerToClientDataTcpPtr senddata_tcp( new ServerToClientDataTcp );
			senddata_tcp->setIP( i, _machines[ i ] );
			server->sendTcp( senddata_tcp );
			_log->add( "NEW CONNECT " + _machines[ i ] );

			updateSheet( );
		}
	}
}

SheetPtr ConnectorForServer::getSheetServer( ) const {
	return _sheet_server;
}

SheetPtr ConnectorForServer::getSheetClient( ) const {
	return _sheet_client;
}