#include "User.h"

User::User( FieldConstPtr field ) : 
Chara ( field ),
_player_num( -1 ) {
}

User::~User( ) {
}

void User::update( ) {
}

void User::setPlayerNum( int player_num ) {
	_player_num = player_num;
}

int User::getPlayerNum( ) const {
	return _player_num;
}