#include "Scene.h"

Scene::Scene( ) {
	_next_scene = SCENE_CONTINUE;
}

Scene::~Scene( ) {
}

void Scene::setNextScene( SCENE next_scene ) {
	_next_scene = next_scene;
}

SCENE Scene::getNextScene( ) const {
	return _next_scene;
}