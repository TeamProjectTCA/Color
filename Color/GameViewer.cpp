#include "GameViewer.h"
#include "Game.h"
#include "Drawer.h"
#include "GameProcessor.h"
#include "ViewField.h"
#include "ViewPlayerUI.h"
#include "ViewChara.h"

GameViewer::GameViewer( GameProcessorConstPtr processor ) {
	_field = ViewFieldPtr( new ViewField( processor->getFieldPtr( ) ) );
	_user_ui = ViewPlayerUIPtr( new ViewPlayerUI( processor->getUserUIPtr( ) ) );
	_enemy_ui = ViewPlayerUIPtr( new ViewPlayerUI( processor->getEnemyUIPtr( ) ) );
	_user = ViewCharaPtr( new ViewChara( processor->getUserPtr( ) ) );
	_enemy = ViewCharaPtr( new ViewChara( processor->getEnemyPtr( ) ) );
}

GameViewer::~GameViewer( ) {
}

void GameViewer::update( ) {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->drawString( 10, 10, "SceneGame", 0xff0000 );

	_field->draw( );
	_user_ui->draw( );
	_enemy_ui->draw( );
	_user->draw( );
	_enemy->draw( );

	drawer->flip( );
}

