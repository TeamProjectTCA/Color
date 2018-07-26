#include "Manager.h"
#include "Drawer.h"
#include "Sound.h"
#include "SceneManager.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "ServerToClientDataUdp.h"

const int WIDTH = 1280;
const int HEIGHT = 720;

int main( ) {
	ManagerPtr manager = Manager::getInstance( );
	manager->setScreenSize( WIDTH, HEIGHT );


	ServerToClientDataUdpPtr recv_data( new ServerToClientDataUdp( ) );
	SceneManagerPtr scene_manager( new SceneManager( recv_data ) );

	DrawerPtr drawer( new Drawer( "Resources/Image" ) );
	SoundPtr soundplayer( new Sound( "Resources/Sound" ) );
	KeyboardPtr keyboard( new Keyboard( ) );
	MousePtr mouse( new Mouse( ) );

	//add
	manager->add( Drawer::getTag( ), drawer );
	manager->add( Sound::getTag( ), soundplayer );
	manager->add( SceneManager::getTag( ), scene_manager );
	manager->add( Keyboard::getTag( ), keyboard );
	manager->add( Mouse::getTag( ), mouse );

	return 0;
}