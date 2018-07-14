#include "ViewSceneCharacterSelect.h"
#include "Drawer.h"

ViewSceneCharacterSelect::ViewSceneCharacterSelect ( ) {
	_drawer = Drawer::getTask ( );
}

ViewSceneCharacterSelect::~ViewSceneCharacterSelect ( ) {
}

void ViewSceneCharacterSelect::update ( ) {
	_drawer->drawString ( 10, 10, "SceneCharacterSelect", 0xff0000 );
	_drawer->flip ( );
}