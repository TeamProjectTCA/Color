#include "ResultProcessor.h"
#include "SceneManager.h"
#include "Client.h"
#include "Drawer.h"

const int FPS = 60;
const int CHANGE_TIME = 5 * FPS;

ResultProcessor::ResultProcessor( ) :
_timer( CHANGE_TIME ) {
}

ResultProcessor::~ResultProcessor( ) {
}

void ResultProcessor::update( ) {
	countChange( );
	if ( _timer <= 0 ) {
		ClientPtr client = Client::getTask( );
		client->setConnectFlag( false );
		_scene_manager = SceneManager::getTask( );
		_scene_manager->setNextScene( SCENE_TITLE );
	}
}

void ResultProcessor::draw( ) const {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->drawString( 10, 10, "SceneResult", 0xff0000 );
}

void ResultProcessor::countChange( ) {
	_timer--;
}