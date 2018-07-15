#include "ViewSceneGame.h"
#include "SceneGame.h"
#include "ViewField.h"
#include "Drawer.h"

ViewSceneGame::ViewSceneGame( SceneGamePtr game ) :
	_scene_game( game ) {
	_drawer = Drawer::getTask( );
	_view_field = ViewFieldPtr( new ViewField( ) );
}

ViewSceneGame::~ViewSceneGame( ) {
}

void ViewSceneGame::update( ) {
	_drawer->drawString( 10, 10, "SceneGame", 0xff0000 );
	_view_field->update( );
	_drawer->flip( );
}

