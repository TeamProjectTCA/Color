#include "ServerController.h"
#include "Manager.h"
#include "ClientToServerData.h"
#include "NWManagerForServer.h"
#include "ServerToClientDataUdp.h"
#include "ProcessorForServer.h"
#include "ViewerForServer.h"

ServerControllerPtr ServerController::getTask( ) {
	return std::dynamic_pointer_cast< ServerController >( Manager::getInstance( )->getTask( getTag( ) ) );
}

ServerController::ServerController( ClientToServerDataConstPtr recvdata ) {
	ServerToClientDataUdpPtr senddata_udp( new ServerToClientDataUdp );

	_processor       = ProcessorForServerPtr( new ProcessorForServer( senddata_udp ) );
	_network_manager = NWManagerForServerPtr( new NWManagerForServer( recvdata, senddata_udp, _processor ) );
	_viewer          = ViewerForServerPtr   ( new ViewerForServer( _processor ) );
}

ServerController::~ServerController( ) {
}

void ServerController::update( ) {
	_viewer->update( );
}