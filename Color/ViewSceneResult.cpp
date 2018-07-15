#include "ViewSceneResult.h"
#include "Drawer.h"


ViewSceneResult::ViewSceneResult( SceneResultPtr result ) :
	_scene_result( result ) {
	_drawer = Drawer::getTask( );
}

ViewSceneResult::~ViewSceneResult( ) {
}

void ViewSceneResult::update( ) {
	_drawer->drawString( 10, 10, "SceneResult", 0xff0000 );
	_drawer->flip( );
}