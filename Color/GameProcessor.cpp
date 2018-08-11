#include "GameProcessor.h"
#include "SceneManager.h"
#include "Keyboard.h"
#include "Field.h"
#include "PlayerUI.h"
#include "Manager.h"
#include "Client.h"
#include "Chara.h"
#include "User.h"
#include "Move.h"

GameProcessor::GameProcessor( ) {
	ManagerPtr manager = Manager::getInstance( );

	int quarter_width  = manager->getScreenWidth( )  / 4;

	const Vector FIELD_ORIGIN = Vector( quarter_width, 0 );
	const Vector PLAYER0_ORIGIN = Vector( );
	const Vector PLAYER1_ORIGIN = Vector( quarter_width * 3, 0 );

	_field = FieldPtr( new Field( FIELD_ORIGIN ) );
	_user_ui = PlayerUIPtr( new PlayerUI( PLAYER0_ORIGIN ) );
	_enemy_ui = PlayerUIPtr( new PlayerUI( PLAYER1_ORIGIN ) );
	
	_user = UserPtr( new User( _field ) );
	_enemy = CharaPtr( new Chara( _field ) );

	_move = MovePtr( new Move( _field, _user ) );
}

GameProcessor::~GameProcessor( ) {
}

void GameProcessor::update( ) {
	KeyboardPtr keyboard = Keyboard::getTask( );

	if ( keyboard->getKeyDown( "z" ) ) {
		SceneManagerPtr scene_manager = SceneManager::getTask( );
		scene_manager->setNextScene( SCENE_RESULT );
		ClientPtr client = Client::getTask( );
		client->setConnectFlag( false );
	}
	_move->update( );
}

void GameProcessor::setUserPos( Vector pos ) {
	_user->setPos( pos );
}

void GameProcessor::setEnemyPos( Vector pos ) {
	_enemy->setPos( pos );
}

void GameProcessor::setPlayerNum( int player_num ) {
	_user->setPlayerNum( player_num );
}

Vector GameProcessor::getClickMas( ) const {
	return _move->getClickMas( );
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