#include "Player.h"

Player::Player( const int PLAYER_NUM, const Vector POS ) :
_PLAYER_NUM( PLAYER_NUM ),
_pos( POS ) {
}

Player::~Player( ) {
}

const int Player::getPlayerNum( ) const {
	return _PLAYER_NUM;
}

Vector Player::getPos( ) const {
	return _pos;
}