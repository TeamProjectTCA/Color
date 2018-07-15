#include "SceneGame.h"
#include "Keyboard.h"
#include "Mouse.h"

SceneGame::SceneGame( ) {
	_keyboard = Keyboard::getTask( );
	_mouse = Mouse::getTask( );

	for ( int i = 0; i < COL * ROW; i++ ) {
		_field_data[ i ] = 0;
	}
}

SceneGame::~SceneGame( ) {
}

void SceneGame::initialize( ) {
}

void SceneGame::update( ) {
	if ( _keyboard->getKeyDown( "z" ) ) {
		setNextScene( SCENE_RESULT );
	}
}