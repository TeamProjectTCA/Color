#include "ResultProcessor.h"
#include "SceneManager.h"
#include "Client.h"
#include "Keyboard.h"

ResultProcessor::ResultProcessor( ) {
}

ResultProcessor::~ResultProcessor( ) {
}

void ResultProcessor::update( ) {
	_keyboard = Keyboard::getTask( );
	if ( _keyboard->getKeyDown( "z" ) ) {
		ClientPtr client = Client::getTask( );
		client->setConnectFlag( false );
		_scene_manager = SceneManager::getTask( );
		_scene_manager->setNextScene( SCENE_TITLE );
	}
}
