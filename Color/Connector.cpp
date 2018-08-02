#include "Connector.h"
#include "Client.h"
#include "SceneManager.h"

const char CONNECTING[ ] = "CONNECTING";
const char READY[ ] = "READY";

Connector::Connector( ) :
_past_state( READY ) {
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

	client->setConnectFlag( false );
	SceneManagerPtr scene_manager = SceneManager::getTask( );
	scene_manager->setNextScene( SCENE_TITLE );
}