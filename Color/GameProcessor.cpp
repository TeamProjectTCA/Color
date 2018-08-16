#include "GameProcessor.h"
#include "SceneManager.h"
#include "Viewer.h"
#include "Field.h"
#include "PlayerUI.h"
#include "Manager.h"
#include "Chara.h"
#include "User.h"
#include "Move.h"
#include "GlobalUI.h"
#include "Drawer.h"

GameProcessor::GameProcessor( ViewerPtr viewer ) :
_gameover( false ) {
	ManagerPtr manager = Manager::getInstance( );

	int quarter_width = manager->getScreenWidth( ) / 4;
	int height = manager->getScreenHeight( );

	const Vector FIELD_ORIGIN = Vector( quarter_width, 0 );
	const Vector GLOBAL_ORIGIN = Vector( );
	const Vector PLAYER0_ORIGIN = Vector( );
	const Vector PLAYER1_ORIGIN = Vector( quarter_width * 3, 0 );

	_field = FieldPtr( new Field( FIELD_ORIGIN ) );
	_global_ui = GlobalUIPtr( new GlobalUI( GLOBAL_ORIGIN ) );
	_user_ui = PlayerUIPtr( new PlayerUI( PLAYER0_ORIGIN ) );
	_enemy_ui = PlayerUIPtr( new PlayerUI( PLAYER1_ORIGIN ) );
	
	_user = UserPtr( new User( _field ) );
	_enemy = CharaPtr( new Chara( _field ) );

	_move = MovePtr( new Move( _field, _user ) );

	viewer->addDrawer( _field );
	viewer->addDrawer( _global_ui );
	viewer->addDrawer( _user_ui );
	viewer->addDrawer( _enemy_ui );
	viewer->addDrawer( _user );
	viewer->addDrawer( _enemy );

}

GameProcessor::~GameProcessor( ) {
}

void GameProcessor::update( ) {
	if ( _gameover ) {
		SceneManagerPtr scene_manager = SceneManager::getTask( );
		scene_manager->setNextScene( SCENE_RESULT );
	}
	_move->update( );
}

void GameProcessor::setUserFieldIdx( Vector pos ) {
	_user->setFieldIdx( pos );
}

void GameProcessor::setEnemyFieldIdx( Vector pos ) {
	_enemy->setFieldIdx( pos );
}

void GameProcessor::setUserPaintCount( int paint_count ) {
	_user_ui->setPaintCount( paint_count );
}

void GameProcessor::setEnemyPaintCount( int paint_count ) {
	_enemy_ui->setPaintCount( paint_count );
}

void GameProcessor::setPlayerNum( int player_num ) {
	_user->setPlayerNum( player_num );
}

void GameProcessor::setTurn( int turn ) {
	_global_ui->setTurn( turn );
}

void GameProcessor::setGameOver( bool gameover ) {
	_gameover = gameover;
}

void GameProcessor::setTileState( int x, int y, FieldProperty::TILE_STATE state ) {
	_field->setTileState( x, y, state );
}

FieldConstPtr GameProcessor::getFieldPtr( ) const {
	return _field;
}

PlayerUIConstPtr GameProcessor::getUserUIPtr( ) const {
	return _user_ui;
}

PlayerUIConstPtr GameProcessor::getEnemyUIPtr( ) const {
	return _enemy_ui;
}

CharaConstPtr GameProcessor::getUserPtr( ) const {
	return _user;
}

CharaConstPtr GameProcessor::getEnemyPtr( ) const {
	return _enemy;
}

GlobalUIPtr GameProcessor::getGlobalUIPtr( ) const {
	return _global_ui;
}