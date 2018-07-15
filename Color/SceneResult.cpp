#include "SceneResult.h"
#include "Keyboard.h"
#include "Mouse.h"

SceneResult::SceneResult( ) {
	_keyboard = Keyboard::getTask( );
	_mouse = Mouse::getTask( );

}

SceneResult::~SceneResult( ) {
}

void SceneResult::initialize( ) {
}

void SceneResult::update( ) {
	if ( _keyboard->getKeyDown( "z" ) ) {
		setNextScene( SCENE_TITLE );
	}
}