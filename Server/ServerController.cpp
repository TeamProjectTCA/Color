#include "ServerController.h"
#include "ProcessorForServer.h"
#include "NWManagerForServer.h"
#include "ViewerForServer.h"
#include "Log.h"
#include "Command.h"
#include "Table.h"

#include "Manager.h"
#include "ClientToServerData.h"
#include "ServerToClientDataTcp.h"
#include "ServerToClientDataUdp.h"

ServerControllerPtr ServerController::getTask( ) {
	return std::dynamic_pointer_cast< ServerController >( Manager::getInstance( )->getTask( getTag( ) ) );
}

ServerController::ServerController( ClientToServerDataConstPtr recvdata ) :
_recvdata( recvdata ) {
}

ServerController::~ServerController( ) {
}

void ServerController::initialize( ) {
	ServerToClientDataUdpPtr senddata_udp( new ServerToClientDataUdp );
	LogPtr log( new Log );
	CommandPtr command( new Command( log ) );
	TablePtr table( new Table );

	_viewer    = ViewerForServerPtr( new ViewerForServer( table ) );
	_network   = NWManagerForServerPtr( new NWManagerForServer( _recvdata, senddata_udp, log, table ) );
	_processor = ProcessorForServerPtr( new ProcessorForServer( senddata_udp, _network, log, command, table ) );
}

void ServerController::update( ) {
	_network->update( );
	_processor->update( );
	_viewer->update( );
}