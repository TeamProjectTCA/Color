#include "SceneChanger.h"
#include "SceneManager.h"

SceneChanger::SceneChanger( SCENE scene ) :
_scene( scene ) {
}

SceneChanger::~SceneChanger( ) {
}

void SceneChanger::onEvent( ) {
	SceneManagerPtr scene = SceneManager::getTask( );
	scene->setNextScene( _scene );
}