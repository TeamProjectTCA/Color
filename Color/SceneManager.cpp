#include "Manager.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Title.h"
#include "NWOption.h"
#include "Game.h"

SceneManagerPtr SceneManager::getTask( ) {
	return std::dynamic_pointer_cast< SceneManager >( Manager::getInstance( )->getTask( getTag( ) ) );
}

SceneManager::SceneManager(  ServerToClientDataTcpConstPtr recvdata_tcp, ServerToClientDataUdpConstPtr recvdata_udp ) :
_recvdata_tcp( recvdata_tcp ),
_recvdata_udp( recvdata_udp ),
_next_scene( SCENE_TITLE ) {
}

SceneManager::~SceneManager( ) {
}

void SceneManager::initialize( ) {
	changeScene( );
}

void SceneManager::finalize( ) {
}

void SceneManager::update( ) {
	_scene->onUpdate( );

	if ( _next_scene != _now_scene ) {
		changeScene( );
	}
}

void SceneManager::changeScene( ) {
	switch ( _next_scene ) {
	case SCENE_TITLE:
		_scene = TitlePtr( new Title( ) );
		break;

	case SCENE_NWOPTION:
		_scene = NWOptionPtr( new NWOption( ) );
		break;

	case SCENE_GAME:
		_scene = GamePtr( new Game( _recvdata_tcp, _recvdata_udp ) );
		break;

	default:
		break;
	}
	_now_scene = _next_scene;
}

void SceneManager::setNextScene( SCENE next_scene ) {
	_next_scene = next_scene;
}