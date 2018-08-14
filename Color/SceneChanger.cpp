#include "SceneChanger.h"
#include "SceneManager.h"

SceneChanger::SceneChanger( SCENE scene ) :
_scene( scene ) {
}

SceneChanger::~SceneChanger( ) {
}

void SceneChanger::start( ) {
	SceneManagerPtr scene = SceneManager::getTask( );
	scene->setNextScene( _scene );
}