#include "SceneChanger.h"
#include "SceneManager.h"

SceneChanger::SceneChanger( SCENE next ) :
_next( next ) {
}

SceneChanger::~SceneChanger( ) {
}

void SceneChanger::activate( ) {
	SceneManagerPtr scene = SceneManager::getTask( );
	scene->setNextScene( _next );
}