#include "ViewSceneTitle.h"
#include "SceneTitle.h"
#include "Drawer.h"

const int WIDTH = 1280;
const int HEIGHT = 720;

const char BACKGROUND_IMAGE[ ] = "back_001";
const char TITLE_IMAGE[ ] = "title";

ViewSceneTitle::ViewSceneTitle( SceneTitlePtr title ) :
	_scene_title( title ) {
	_drawer = Drawer::getTask( );

	//_bg_image = _drawer->getImage( BACKGROUND_IMAGE );
	//_title_image = _drawer->getImage( TITLE_IMAGE );
}

ViewSceneTitle::~ViewSceneTitle( ) {
}

void ViewSceneTitle::update( ) {
	_drawer->drawString( 10, 10, "SceneTitle", 0xff0000 );
	drawBackGround( );
	drawTitleLogo( );
	_drawer->flip( );
}

void ViewSceneTitle::drawTitleLogo( ) const {
	//_drawer->drawRotaGraph( WIDTH / 2, HEIGHT / 4, 1, 0, _title_image, true );
}

void ViewSceneTitle::drawBackGround( ) const {
	//_drawer->drawRotaGraph( WIDTH / 2, HEIGHT / 2, 1, 0, _bg_image, true );
}