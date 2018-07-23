#include "ResultProcessor.h"
#include "SceneManager.h"
#include "Keyboard.h"
#include "Mouse.h"

ResultProcessor::ResultProcessor( ) {
	_scene_manager = SceneManager::getTask( );
	_keyboard = Keyboard::getTask( );
	_mouse = Mouse::getTask( );
}

ResultProcessor::~ResultProcessor( ) {
}

void ResultProcessor::update( ) {
	if ( _keyboard->getKeyDown( "z" ) ) {
		_scene_manager->setNextScene( SCENE_TITLE );
	}
}
