#include "Connector.h"
#include "Client.h"
#include "SceneManager.h"

const char CONNECTING[ ] = "CONNECTING";

Connector::Connector( ) {
}

Connector::~Connector( ) {
}

void Connector::update( ) {
	checkConnect( );
}

void Connector::checkConnect( ) {
	ClientPtr client = Client::getTask( );
	std::string state = client->getPhase( );

	if ( state == _past_state ) {
		return;
	}
	_past_state = state;

	if ( state == CONNECTING ) {
		return;
	}

	SceneManagerPtr scene_manager = SceneManager::getTask( );
	scene_manager->setNextScene( SCENE_TITLE );
}