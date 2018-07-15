#include "Manager.h"
#include "SceneManager.h"
#include "Scene.h"
#include "SceneTitle.h"
#include "SceneCharacterSelect.h"
#include "SceneGame.h"
#include "SceneResult.h"
#include "ViewSceneTitle.h"
#include "ViewSceneCharacterSelect.h"
#include "ViewSceneGame.h"
#include "ViewSceneResult.h"

SceneManagerPtr SceneManager::getTask( ) {
	return std::dynamic_pointer_cast< SceneManager >( Manager::getInstance( )->getTask( getTag( ) ) );
}

std::string SceneManager::getTag( ) {
	return "SCENE_MANAGER";
}

SceneManager::SceneManager( ) {
}

SceneManager::~SceneManager( ) {
}

void SceneManager::initialize( ) {
	_scene = SceneTitlePtr( new SceneTitle( ) );
	_view_scene = ViewSceneTitlePtr( new ViewSceneTitle( _scene_title ) );
}

void SceneManager::finalize( ) {
}

void SceneManager::update( ) {
	_scene->update( );
	_view_scene->update( );

	changeScene( );
}

void SceneManager::changeScene( ) {
	if ( _scene->getNextScene( ) == SCENE_CONTINUE ) {
		return;
	}

	switch ( _scene->getNextScene( ) ) {
	case SCENE_TITLE:
		_scene = SceneTitlePtr( new SceneTitle( ) );
		_view_scene = ViewSceneTitlePtr( new ViewSceneTitle( _scene_title ) );
		break;

	case SCENE_CHARACTERSELECT:
		_scene = SceneCharacterSelectPtr( new SceneCharacterSelect( ) );
		_view_scene = ViewSceneCharacterSelectPtr( new ViewSceneCharacterSelect( _scene_character_select ) );
		break;

	case SCENE_GAME:
		_scene = SceneGamePtr( new SceneGame( ) );
		_view_scene = ViewSceneGamePtr( new ViewSceneGame( _scene_game ) );
		break;

	case SCENE_RESULT:
		_scene = SceneResultPtr( new SceneResult( ) );
		_view_scene = ViewSceneResultPtr( new ViewSceneResult( _scene_result ) );
		break;
	}
}
