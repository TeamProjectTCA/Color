#include "SceneCharacterSelect.h"
#include "Keyboard.h"
#include "Mouse.h"

SceneCharacterSelect::SceneCharacterSelect( ) {
	_keyboard = Keyboard::getTask( );
	_mouse = Mouse::getTask( );

}

SceneCharacterSelect::~SceneCharacterSelect( ) {
}

void SceneCharacterSelect::initialize( ) {
}

void SceneCharacterSelect::update( ) {
	if ( _keyboard->getKeyDown( "z" ) ) {
		setNextScene( SCENE_GAME );
	}
}