#include "User.h"
#include "Drawer.h"

User::User( FieldConstPtr field ) : 
Chara ( field ),
_player_num( -1 ) {
}

User::~User( ) {
}

void User::update( ) {
}

void User::draw( ) const {
	DrawerPtr drawer = Drawer::getTask( );
	Vector pos = getScreenPos( );

	drawer->drawCircle( ( float ) pos.x, ( float ) pos.y, 10, 0x000000, true );
}

void User::setPlayerNum( int player_num ) {
	_player_num = player_num;
}

int User::getPlayerNum( ) const {
	return _player_num;
}