#include "ServerToClientDataUdp.h"

ServerToClientDataUdp::ServerToClientDataUdp( ) {
	_data = Pack( );
}

ServerToClientDataUdp::~ServerToClientDataUdp( ) {
}

void ServerToClientDataUdp::setPlayerPos( int idx, Vector pos ) {
	_data.player[ idx ].x = ( unsigned char )pos.x;
	_data.player[ idx ].y = ( unsigned char )pos.y;
}

void ServerToClientDataUdp::setTurn( int turn ) {
	_data.turn = turn;
}

Vector ServerToClientDataUdp::getPlayerPos( int idx ) const {
	Vector pos = Vector( _data.player[ idx ].x, _data.player[ idx ].y );
	return pos;
}

int ServerToClientDataUdp::getTurn( ) const {
	return _data.turn;
}

int ServerToClientDataUdp::getSize( ) const {
	return sizeof( _data );
}

void* ServerToClientDataUdp::getPtr( ) {
	return &_data;
}
