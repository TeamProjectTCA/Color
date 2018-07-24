#include "ServerController.h"
#include "Manager.h"
#include "ClientToServerData.h"
#include "NWManagerForServer.h"
#include "ServerToClientDataUdp.h"
#include "ProcessorForServer.h"
#include "ViewerForServer.h"
#include "Log.h"

ServerControllerPtr ServerController::getTask( ) {
	return std::dynamic_pointer_cast< ServerController >( Manager::getInstance( )->getTask( getTag( ) ) );
}

ServerController::ServerController( ClientToServerDataConstPtr recvdata ) {
	ServerToClientDataUdpPtr senddata_udp( new ServerToClientDataUdp );
	LogPtr log( new Log( ) );

	_processor       = ProcessorForServerPtr( new ProcessorForServer( senddata_udp, log ) );
	_network_manager = NWManagerForServerPtr( new NWManagerForServer( recvdata, senddata_udp, _processor, log ) );
	_viewer          = ViewerForServerPtr   ( new ViewerForServer( _processor, _network_manager, log ) );
}

ServerController::~ServerController( ) {
}

void ServerController::initialize( ) {
	_network_manager->initialize( );
	_viewer->initialize( );
}

void ServerController::update( ) {
	_network_manager->update( );
	_viewer->update( );
}