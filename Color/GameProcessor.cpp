#include "GameProcessor.h"
#include "SceneManager.h"
#include "Keyboard.h"
#include "Field.h"
#include "PlayerUI.h"
#include "Manager.h"
#include "Client.h"

GameProcessor::GameProcessor( ) {
	ManagerPtr manager = Manager::getInstance( );

	int quarter_width  = manager->getScreenWidth( )  / 4;

	const Vector FIELD_ORIGIN = Vector( quarter_width, 0 );
	const Vector PLAYER1_ORIGIN = Vector( );
	const Vector PLAYER2_ORIGIN = Vector( quarter_width * 3, 0 );

	_field = FieldPtr( new Field( FIELD_ORIGIN ) );
	_player1_ui = PlayerUIPtr( new PlayerUI( PLAYER1_ORIGIN ) );
	_player2_ui = PlayerUIPtr( new PlayerUI( PLAYER2_ORIGIN ) );
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

FieldConstPtr GameProcessor::getFieldPtr( ) const {
	return _field;
}

PlayerUIConstPtr GameProcessor::getPlayer1UIPtr( ) const {
	return _player1_ui;
}

PlayerUIConstPtr GameProcessor::getPlayer2UIPtr( ) const {
	return _player2_ui;
}