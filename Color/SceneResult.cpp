#include "SceneResult.h"
#include "ViewSceneResult.h"
#include "Keyboard.h"
#include "Mouse.h"

SceneResult::SceneResult ( ) {
	_keyboard = Keyboard::getTask ( );
	_mouse = Mouse::getTask ( );
	
	_view_result = ViewSceneResultPtr ( new ViewSceneResult ( ) );
}

SceneResult::~SceneResult ( ) {
}

void SceneResult::initialize ( ) {
}

void SceneResult::update ( ) {
	_view_result->update ( );

	if ( _keyboard->getKeyDown ( "z" ) ) {
		setNextScene ( SCENE_TITLE );
	}
}