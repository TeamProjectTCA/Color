#include "User.h"
#include "Drawer.h"

User::User( FieldConstPtr field ) : 
Chara ( field ),
_player_idx( -1 ) {
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

void User::setPlayerIdx( int player_idx ) {
	_player_idx = player_idx;
}

int User::getPlayerIdx( ) const {
	return _player_idx;
}