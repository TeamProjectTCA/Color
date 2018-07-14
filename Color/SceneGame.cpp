#include "SceneGame.h"
#include "ViewSceneGame.h"
#include "Keyboard.h"
#include "Mouse.h"

SceneGame::SceneGame ( ) {
	_keyboard = Keyboard::getTask ( );
	_mouse = Mouse::getTask ( );

	_view_game = ViewSceneGamePtr ( new ViewSceneGame ( ) );
}

SceneGame::~SceneGame ( ) {
}

void SceneGame::initialize ( ) {
}

void SceneGame::update ( ) {
	_view_game->update ( );

	if ( _keyboard->getKeyDown ( "z" ) ) {
		setNextScene ( SCENE_RESULT );
	}
}