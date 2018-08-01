#include "GameProcessor.h"
#include "SceneManager.h"
#include "Keyboard.h"
#include "Field.h"
#include "PlayerUI.h"
#include "Manager.h"
#include "Client.h"
#include "Chara.h"

GameProcessor::GameProcessor( ) {
	ManagerPtr manager = Manager::getInstance( );

	int quarter_width  = manager->getScreenWidth( )  / 4;

	const Vector FIELD_ORIGIN = Vector( quarter_width, 0 );
	const Vector PLAYER0_ORIGIN = Vector( );
	const Vector PLAYER1_ORIGIN = Vector( quarter_width * 3, 0 );

	_field = FieldPtr( new Field( FIELD_ORIGIN ) );
	_player0_ui = PlayerUIPtr( new PlayerUI( PLAYER0_ORIGIN ) );
	_player1_ui = PlayerUIPtr( new PlayerUI( PLAYER1_ORIGIN ) );

	_player0 = CharaPtr( new Chara( _field ) );
	_player1 = CharaPtr( new Chara( _field ) );
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
}

void GameProcessor::setPlayer0Pos( Vector pos ) {
	_player0->setPos( pos );
}

void GameProcessor::setPlayer1Pos( Vector pos ) {
	_player1->setPos( pos );
}

FieldConstPtr GameProcessor::getFieldPtr( ) const {
	return _field;
}

PlayerUIConstPtr GameProcessor::getPlayer0UIPtr( ) const {
	return _player0_ui;
}

PlayerUIConstPtr GameProcessor::getPlayer1UIPtr( ) const {
	return _player1_ui;
}

CharaConstPtr GameProcessor::getPlayer0Ptr( ) const {
	return _player0;
}

CharaConstPtr GameProcessor::getPlayer1Ptr( ) const {
	return _player1;
}