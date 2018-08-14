#include "ServerController.h"
#include "Manager.h"
#include "ClientToServerData.h"
#include "NWManagerForServer.h"
#include "ServerToClientDataUdp.h"
#include "ServerToClientDataTcp.h"
#include "ProcessorForServer.h"
#include "ViewerForServer.h"
#include "Log.h"
#include "Command.h"

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
	LogPtr log( new Log( ) );
	CommandPtr command( new Command( log ) );

	_processor       = ProcessorForServerPtr( new ProcessorForServer( senddata_udp, log, command ) );
	_network_manager = NWManagerForServerPtr( new NWManagerForServer( _recvdata, senddata_udp, _processor, log ) );
	_viewer          = ViewerForServerPtr   ( new ViewerForServer( _processor, _network_manager, log, command ) );
}

void ServerController::update( ) {
	_network_manager->update( );
	_processor->update( );
	_viewer->update( );
}