#include "SceneCharacterSelect.h"
#include "ViewSceneCharacterSelect.h"
#include "Keyboard.h"
#include "Mouse.h"

SceneCharacterSelect::SceneCharacterSelect ( ) {
	_keyboard = Keyboard::getTask ( );
	_mouse = Mouse::getTask ( );

	_view_chara_select = ViewSceneCharacterSelectPtr ( new ViewSceneCharacterSelect ( ) );
}

SceneCharacterSelect::~SceneCharacterSelect ( ) {
}

void SceneCharacterSelect::initialize ( ) {
}

void SceneCharacterSelect::update ( ) {
	_view_chara_select->update ( );

	if ( _keyboard->getKeyDown ( "z" ) ) {
		setNextScene ( SCENE_GAME );
	}
}