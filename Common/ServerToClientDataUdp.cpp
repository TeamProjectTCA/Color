#include "ServerToClientDataUdp.h"

ServerToClientDataUdp::ServerToClientDataUdp( ) {
	_data = Pack( );
}

ServerToClientDataUdp::~ServerToClientDataUdp( ) {
}

void ServerToClientDataUdp::setPlayer0Pos( Vector pos ) {
	_data.player0.x = ( unsigned char )pos.x;
	_data.player0.y = ( unsigned char )pos.y;
}

void ServerToClientDataUdp::setPlayer1Pos( Vector pos ) {
	_data.player1.x = ( unsigned char )pos.x;
	_data.player1.y = ( unsigned char )pos.y;
}

Vector ServerToClientDataUdp::getPlayer0Pos( ) const {
	Vector pos = Vector( _data.player0.x, _data.player0.y );
	return pos;
}

Vector ServerToClientDataUdp::getPlayer1Pos( ) const {
	Vector pos = Vector( _data.player1.x, _data.player1.y );
	return pos;
}

int ServerToClientDataUdp::getSize( ) const {
	return sizeof( _data );
}

void* ServerToClientDataUdp::getPtr( ) {
	return &_data;
}
