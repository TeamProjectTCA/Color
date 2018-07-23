#include "GameViewer.h"
#include "Game.h"
#include "FieldViewer.h"
#include "Drawer.h"

GameViewer::GameViewer( GameProcessorPtr game ) :
_scene_game( game ) {
	_drawer = Drawer::getTask( );
	_view_field = FieldViewerPtr( new FieldViewer( ) );
}

GameViewer::~GameViewer( ) {
}

void GameViewer::update( ) {
	_drawer->drawString( 10, 10, "SceneGame", 0xff0000 );
	_view_field->update( );
	_drawer->flip( );
}

