#include "Manager.h"
#include "Drawer.h"
#include "Server.h"
#include "ClientToServerData.h"
#include "ServerController.h"

int main( ) {
	ClientToServerDataPtr recvdata( new ClientToServerData );
	ServerControllerPtr controller( new ServerController( recvdata ) );

	ManagerPtr manager = Manager::getInstance( );
	manager->add( Drawer::getTag( ), DrawerPtr( new Drawer( "Resources/Image" ) ) );
	manager->add( Server::getTag( ), ServerPtr( new Server( recvdata ) ) );

	manager->add( ServerController::getTag( ), controller );

	return 0;
}