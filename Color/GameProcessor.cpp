#include "GameProcessor.h"
#include "SceneManager.h"
#include "Keyboard.h"
#include "Mouse.h"

GameProcessor::GameProcessor( ) {
	_scene_manager = SceneManager::getTask( );
	_keyboard = Keyboard::getTask( );
	_mouse = Mouse::getTask( );
}

GameProcessor::~GameProcessor( ) {
}

void GameProcessor::update( ) {
	if ( _keyboard->getKeyDown( "z" ) ) {
		_scene_manager->setNextScene( SCENE_RESULT );
	}
}