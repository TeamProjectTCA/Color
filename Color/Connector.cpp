#include "Connector.h"

Connector::Connector( ) {
	_scene_manager = SceneManager::getTask( );
}

Connector::~Connector( ) {
}

void Connector::initialize( ) {
}

void Connector::update( ) {
	checkConnect( );
}

void Connector::checkConnect( ) {
	ClientPtr client = Client::getTask( );

	if ( client->getPhase( ) == "CONNECTING" ) {
		client->setConnectFlag( false );
		_scene_manager->setNextScene( SCENE_TITLE );
	}
}