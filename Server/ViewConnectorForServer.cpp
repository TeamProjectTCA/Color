#include "ViewConnectorForServer.h"
#include "ConnectorForServer.h"
#include "Sheet.h"
#include "Server.h"

const short int ROW_NUM = Server::MAX_MACHINES + 1;
const short int TAG_PITCH_ID = 100;
const short int TAG_PITCH_IP = 150;

ViewConnectorForServer::ViewConnectorForServer( ConnectorForServerConstPtr connector ) :
_connector( connector ) {
	_sheet_server = SheetPtr( new Sheet( 1 ) );
	_sheet_server->addCol( TAG_PITCH_ID );
	_sheet_server->addCol( TAG_PITCH_IP );
	_sheet_server->write( 0, 0, "SERVER IP" );
	_sheet_server->write( 1, 0, _connector->getServerIp( ) );

	_sheet_client = SheetPtr( new Sheet( ROW_NUM ) );
	_sheet_client->addCol( TAG_PITCH_ID );
	_sheet_client->addCol( TAG_PITCH_IP );
	_sheet_client->write( 0, 0, "CLIENT ID" );
	_sheet_client->write( 1, 0, "CLIENT IP" );

	updateSheet( );
}

ViewConnectorForServer::~ViewConnectorForServer( ) {
}

void ViewConnectorForServer::updateSheet( ) {
	// client
	for ( int i = 0; i < Server::MAX_MACHINES; i++ ) {
		_sheet_client->write( 0, i + 1, std::to_string( i ) );
		_sheet_client->write( 1, i + 1, _connector->getMachinesIp( i ) );
	}
}

SheetPtr ViewConnectorForServer::getSheetServer( ) const {
	return _sheet_server;
}

SheetPtr ViewConnectorForServer::getSheetClient( ) const {
	return _sheet_client;
}