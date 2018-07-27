#include "Manager.h"
#include "Drawer.h"
#include "Server.h"
#include "ClientToServerData.h"
#include "ServerController.h"
#include "Keyboard.h"

int main( ) {
	ManagerPtr manager = Manager::getInstance( );
	manager->setWindowSize( 1280, 720 );

	ClientToServerDataPtr recvdata( new ClientToServerData );
	ServerControllerPtr controller( new ServerController( recvdata ) );

	manager->add( Drawer::getTag( ), DrawerPtr( new Drawer( "Resources/Image" ) ) );
	manager->add( Server::getTag( ), ServerPtr( new Server( recvdata ) ) );
	manager->add( Keyboard::getTag( ), KeyboardPtr( new Keyboard( ) ) );

	manager->add( ServerController::getTag( ), controller );
	return 0;
}