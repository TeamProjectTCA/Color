#include "Manager.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Title.h"
#include "NWOption.h"
#include "CharacterSelect.h"
#include "Game.h"
#include "Result.h"
#include "Viewer.h"

SceneManagerPtr SceneManager::getTask( ) {
	return std::dynamic_pointer_cast< SceneManager >( Manager::getInstance( )->getTask( getTag( ) ) );
}

std::string SceneManager::getTag( ) {
	return "SCENE_MANAGER";
}

SceneManager::SceneManager(  ServerToClientDataTcpConstPtr recvdata_tcp, ServerToClientDataUdpConstPtr recvdata_udp ) :
_recvdata_tcp( recvdata_tcp ),
_recvdata_udp( recvdata_udp ) {
}

SceneManager::~SceneManager( ) {
}

void SceneManager::initialize( ) {
	_viewer = ViewerPtr( new Viewer );
	_scene = TitlePtr( new Title( _viewer ) );
}

void SceneManager::finalize( ) {
}

void SceneManager::update( ) {
	_scene->update( );
	_viewer->update( );

	changeScene( );
}

void SceneManager::changeScene( ) {
	if ( _scene->getNextScene( ) == SCENE_CONTINUE ) {
		return;
	}

	_viewer->resetDrawer( );

	switch ( _scene->getNextScene( ) ) {
	case SCENE_TITLE:
		_scene = TitlePtr( new Title( _viewer ) );
		break;

	case SCENE_NWOPTION:
		_scene = NWOptionPtr( new NWOption( ) );
		break;

	case SCENE_CHARACTERSELECT:
		_scene = CharacterSelectPtr( new CharacterSelect( ) );
		break;

	case SCENE_GAME:
		_scene = GamePtr( new Game( _recvdata_tcp, _recvdata_udp, _viewer ) );
		break;

	case SCENE_RESULT:
		_scene = ResultPtr( new Result( _viewer ) );
		break;

	default:
		return;
	}
}

void SceneManager::setNextScene( SCENE next_scene ) {
	_scene->setNextScene( next_scene );
}