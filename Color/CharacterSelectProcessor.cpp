#include "CharacterSelectProcessor.h"
#include "SceneManager.h"
#include "Keyboard.h"
#include "Mouse.h"

CharacterSelectProcessor::CharacterSelectProcessor( ) {
	_scene_manager = SceneManager::getTask( );
	_keyboard = Keyboard::getTask( );
	_mouse = Mouse::getTask( );
}

CharacterSelectProcessor::~CharacterSelectProcessor( ) {
}

void CharacterSelectProcessor::update( ) {
	if ( _keyboard->getKeyDown( "z" ) ) {
		_scene_manager->setNextScene( SCENE_GAME );
	}
}