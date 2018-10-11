#include "NWOption.h"
#include "SceneManager.h"

#include "Keyboard.h"
#include "Client.h"
#include "Manager.h"
#include "Drawer.h"

const int MAX_LENGTH = 15;

NWOption::NWOption( ) :
_new_ip( ),
_act( ACT_WAIT ) {
}

NWOption::~NWOption( ) {
}

void NWOption::update( ) {
	updateAct( );

	switch ( _act ) {
	case ACT_WAIT:
		break;
	case ACT_INPUT:
		actOnInput( );
		break;
	case ACT_DELETE:
		actOnDelete( );
		break;
	case ACT_ENTER:
		actOnEnter( );
		break;
	}
	_act = ACT_WAIT;
}

void NWOption::updateAct( ) {
	KeyboardPtr keyboard = Keyboard::getTask( );

	if ( keyboard->getKeyDown( "BACK" ) ) {
		_act = ACT_DELETE;
	}

	if ( !keyboard->getString( ).empty( ) ) {
		_act = ACT_INPUT;
	}

	if ( keyboard->getKeyDown( "ENTER" ) ) {
		_act = ACT_ENTER;
	}
}

void NWOption::actOnInput( ) {
	if ( _new_ip.length( ) >= MAX_LENGTH ) {
		return;
	}

	KeyboardPtr keyboard = Keyboard::getTask( );
	
	std::string input = keyboard->getString( );
	if ( !keyboard->getKeyDown( input ) ) {
		return;
	}

	int ascii = input[ 0 ];
	if ( '0' <= ascii && ascii <= '9' || ascii == '.' ) {
		_new_ip.push_back( ascii );
	}
}

void NWOption::actOnDelete( ) {
	if ( _new_ip.empty( ) ) {
		return;
	}
	_new_ip.pop_back( );
}

void NWOption::actOnEnter( ) {
	ClientPtr client = Client::getTask( );
	client->readIP( _new_ip );
	SceneManager::getTask( )->setNextScene( SCENE_TITLE );
}

void NWOption::draw( ) const {
	ManagerPtr manager = Manager::getInstance( );
	int width  = manager->getScreenWidth( );
	int height = manager->getScreenHeight( );

	Vector now_ip_pos = Vector( width / 2, height / 3 );
	Vector new_ip_pos = Vector( width / 2, height / 2 );

	DrawerPtr drawer = Drawer::getTask( );
	ClientPtr client = Client::getTask( );
	drawer->drawFormatStringCenter( ( float )now_ip_pos.x, ( float )now_ip_pos.y, 0xffffff, client->getServerIP( ).c_str( ) );
	drawer->drawFormatStringCenter( ( float )new_ip_pos.x, ( float )new_ip_pos.y, 0xffffff, _new_ip.c_str( ) );
}