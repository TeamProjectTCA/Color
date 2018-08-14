#include "ViewConnectorForServer.h"
#include "ConnectorForServer.h"
#include "Sheet.h"
#include "Server.h"

const short int ROW_NUM = Server::MAX_MACHINES + 1;
const short int TAG_PITCH_ID = 50;
const short int TAG_PITCH_IP = 200;

ViewConnectorForServer::ViewConnectorForServer( ConnectorForServerConstPtr connector ) :
_connector( connector ) {
	_sheet = SheetPtr( new Sheet( ROW_NUM ) );
	_sheet->addCol( TAG_PITCH_ID );
	_sheet->addCol( TAG_PITCH_IP );
	_sheet->write( 0, 0, "ID" );
	_sheet->write( 1, 0, "IP" );

	updateSheet( );
}

ViewConnectorForServer::~ViewConnectorForServer( ) {
}

void ViewConnectorForServer::updateSheet( ) {
	for ( int i = 0; i < Server::MAX_MACHINES; i++ ) {
		_sheet->write( 0, i + 1, std::to_string( i ) );
		_sheet->write( 1, i + 1, _connector->getMachinesIp( i ) );
	}
}

SheetPtr ViewConnectorForServer::getSheet( ) const {
	return _sheet;
}