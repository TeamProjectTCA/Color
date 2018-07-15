#include "Manager.h"
#include "Drawer.h"
#include "Sound.h"
#include "SceneManager.h"
#include "Keyboard.h"
#include "Mouse.h"

const int WIDTH = 1280;
const int HEIGHT = 720;
const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

int main( ) {
	ManagerPtr manager = Manager::getInstance( );
	manager->setScreenSize( WIDTH, HEIGHT );
	manager->setWindowSize( WINDOW_WIDTH, WINDOW_HEIGHT );

	DrawerPtr drawer( new Drawer( "Resources/Image" ) );
	SoundPtr soundplayer( new Sound( "Resources/Sound" ) );
	SceneManagerPtr scene_manager( new SceneManager( ) );
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