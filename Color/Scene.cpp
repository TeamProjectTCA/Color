#include "Scene.h"
#include "Drawer.h"

Scene::Scene( ) {
}

Scene::~Scene( ) {
}

void Scene::onUpdate( ) {
	update( );
	draw( );

	DrawerPtr drawer = Drawer::getTask( );
	drawer->flip( );
}