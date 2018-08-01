#include "GameViewer.h"
#include "Game.h"
#include "Drawer.h"
#include "GameProcessor.h"
#include "ViewField.h"
#include "ViewPlayerUI.h"
#include "ViewChara.h"

GameViewer::GameViewer( GameProcessorConstPtr processor ) {
	_field = ViewFieldPtr( new ViewField( processor->getFieldPtr( ) ) );
	_player0_ui = ViewPlayerUIPtr( new ViewPlayerUI( processor->getPlayer0UIPtr( ) ) );
	_player1_ui = ViewPlayerUIPtr( new ViewPlayerUI( processor->getPlayer1UIPtr( ) ) );
	_player0 = ViewCharaPtr( new ViewChara( processor->getPlayer0Ptr( ) ) );
	_player1 = ViewCharaPtr( new ViewChara( processor->getPlayer1Ptr( ) ) );
}

GameViewer::~GameViewer( ) {
}

void GameViewer::update( ) {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->drawString( 10, 10, "SceneGame", 0xff0000 );

	_field->draw( );
	_player0_ui->draw( );
	_player1_ui->draw( );
	_player0->draw( );
	_player1->draw( );

	drawer->flip( );
}

