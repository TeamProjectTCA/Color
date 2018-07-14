#include "SceneTitle.h"
#include "ViewSceneTitle.h"
#include "Keyboard.h"
#include "Mouse.h"

SceneTitle::SceneTitle ( ) {
	_keyboard = Keyboard::getTask ( );
	_mouse = Mouse::getTask ( );
	
	_view_title = ViewSceneTitlePtr ( new ViewSceneTitle ( ) );
}

SceneTitle::~SceneTitle ( ) {
}

void SceneTitle::initialize ( ) {
}

void SceneTitle::update ( ) {
	_view_title->update ( );

	if ( _keyboard->getKeyDown ( "z" ) ) {
		setNextScene ( SCENE_CHARACTERSELECT );
	}
}