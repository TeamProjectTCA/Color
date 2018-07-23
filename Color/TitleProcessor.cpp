#include "TitleProcessor.h"
#include "SceneManager.h"
#include "Keyboard.h"
#include "Mouse.h"

const int WIDTH = 1280;
const int HEIGHT = 720;

TitleProcessor::TitleProcessor( ) {
	_scene_manager = SceneManager::getTask( );
	_keyboard = Keyboard::getTask( );
	_mouse = Mouse::getTask( );

	_bg_pos = Vector( WIDTH / 2, HEIGHT / 2 );
	_logo_pos = Vector( WIDTH / 2, HEIGHT / 4 );
}


TitleProcessor::~TitleProcessor( ) {
}

void TitleProcessor::update( ) {
	if ( _keyboard->getKeyDown( "z" ) ) {
		_scene_manager->setNextScene( SCENE_CHARACTERSELECT );
	}
}

Vector TitleProcessor::getBgPos( ) {
	return _bg_pos;
}

Vector TitleProcessor::getLogoPos( ) {
	return _logo_pos;
}