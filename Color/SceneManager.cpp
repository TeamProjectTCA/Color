#include "Manager.h"
#include "SceneManager.h"
#include "SceneTitle.h"
#include "SceneCharacterSelect.h"
#include "SceneGame.h"
#include "SceneResult.h"

SceneManagerPtr SceneManager::getTask ( ) {
	return std::dynamic_pointer_cast< SceneManager >( Manager::getInstance ( )->getTask ( getTag ( ) ) );
}

std::string SceneManager::getTag ( ) {
	return "SCENE_MANAGER";
}

SceneManager::SceneManager ( ) {
}

SceneManager::~SceneManager ( ) {
}

void SceneManager::initialize ( ) {
	_scene = SceneTitlePtr ( new SceneTitle ( ) );
}

void SceneManager::finalize ( ) {
}

void SceneManager::update ( ) {
	_scene->update ( );

	changeScene ( );
}

void SceneManager::changeScene ( ) {
	if ( _scene->getNextScene ( ) == SCENE_CONTINUE ) {
		return;
	}

	switch ( _scene->getNextScene ( ) ) {
	case SCENE_TITLE:
		_scene = SceneTitlePtr ( new SceneTitle ( ) );
		break;

	case SCENE_CHARACTERSELECT:
		_scene = SceneCharacterSelectPtr ( new SceneCharacterSelect ( ) );
		break;

	case SCENE_GAME:
		_scene = SceneGamePtr ( new SceneGame ( ) );
		break;

	case SCENE_RESULT:
		_scene = SceneResultPtr ( new SceneResult ( ) );
		break;
	}
}
