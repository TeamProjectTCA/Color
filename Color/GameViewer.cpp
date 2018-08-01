#include "GameViewer.h"
#include "Game.h"
#include "Drawer.h"
#include "GameProcessor.h"
#include "ViewField.h"
#include "ViewPlayerUI.h"

GameViewer::GameViewer( GameProcessorConstPtr processor ) {
	_field = ViewFieldPtr( new ViewField( processor->getFieldPtr( ) ) );
	_player1_ui = ViewPlayerUIPtr( new ViewPlayerUI( processor->getPlayer1UIPtr( ) ) );
	_player2_ui = ViewPlayerUIPtr( new ViewPlayerUI( processor->getPlayer2UIPtr( ) ) );
}

GameViewer::~GameViewer( ) {
}

void GameViewer::update( ) {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->drawString( 10, 10, "SceneGame", 0xff0000 );

	_field->draw( );
	_player1_ui->draw( );
	_player2_ui->draw( );

	drawer->flip( );
}

