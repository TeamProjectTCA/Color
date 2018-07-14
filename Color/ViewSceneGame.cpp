#include "ViewSceneGame.h"
#include "Drawer.h"

ViewSceneGame::ViewSceneGame ( ) {
	_drawer = Drawer::getTask ( );
}

ViewSceneGame::~ViewSceneGame ( ) {
}

void ViewSceneGame::update ( ) {
	_drawer->drawString ( 10, 10, "SceneGame", 0xff0000 );
	_drawer->flip ( );
}