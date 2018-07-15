#include "SceneTitle.h"
#include "Keyboard.h"
#include "Mouse.h"

SceneTitle::SceneTitle( ) {
	_keyboard = Keyboard::getTask( );
	_mouse = Mouse::getTask( );
}

SceneTitle::~SceneTitle( ) {
}

void SceneTitle::initialize( ) {
}

void SceneTitle::update( ) {
	if ( _keyboard->getKeyDown( "z" ) ) {
		setNextScene( SCENE_CHARACTERSELECT );
	}
}