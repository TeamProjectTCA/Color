#include "NWOptionProcessor.h"
#include "Keyboard.h"
#include "SceneManager.h"
#include "Client.h"
#include "Manager.h"

const int MAX_LENGTH = 15;

NWOptionProcessor::NWOptionProcessor( ) :
_new_ip_pos( Vector( ) ),
_now_ip_pos( Vector( ) ) {
	ClientPtr client = Client::getTask( );
	_now_ip = client->getServerIP( );

	ManagerPtr manager = Manager::getInstance( );
	int width  = manager->getScreenWidth( );
	int height = manager->getScreenHeight( );

	_now_ip_pos.x = width / 2;
	_now_ip_pos.y = height / 3;

	_new_ip_pos.x = width / 2;
	_new_ip_pos.y = height / 2;
}

NWOptionProcessor::~NWOptionProcessor( ) {
}

void NWOptionProcessor::update( ) {
	write( );

	KeyboardPtr keyboard = Keyboard::getTask( );

	if ( keyboard->getKeyDown( "ENTER" ) ) {
		if ( !_new_ip.empty( ) ) {
			ClientPtr client = Client::getTask( );
			client->readIP( _new_ip );
		}

		SceneManagerPtr scene_manager = SceneManager::getTask( );
		scene_manager->setNextScene( SCENE_TITLE );
	}
}

void NWOptionProcessor::write( ) {
	KeyboardPtr keyboard = Keyboard::getTask( );

	if ( keyboard->getKeyDown( "BACK" ) && !_new_ip.empty( ) ) {
		_new_ip.pop_back( );
		return;
	}

	std::string input = keyboard->getString( );
	if ( !keyboard->getKeyDown( input ) ) {
		return;
	}

	if ( _new_ip.length( ) >= MAX_LENGTH ) {
		return;
	}

	int ascii = input[ 0 ];
	if ( ( ascii < '0' || '9' < ascii ) && ascii != '.' ) {
		return;
	}

	_new_ip.push_back( input[ 0 ] );
}

std::string NWOptionProcessor::getNowIP( ) const {
	return _now_ip;
}

std::string NWOptionProcessor::getNewIP( ) const {
	return _new_ip;
}

Vector NWOptionProcessor::getNowIPPos( ) const {
	return _now_ip_pos;
}

Vector NWOptionProcessor::getNewIPPos( ) const {
	return _new_ip_pos;
}