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

Vector ServerToClientDataUdp::getPlayerPos( int idx ) const {
	Vector pos = Vector( _data.player[ idx ].x, _data.player[ idx ].y );
	return pos;
}

int ServerToClientDataUdp::getSize( ) const {
	return sizeof( _data );
}

void* ServerToClientDataUdp::getPtr( ) {
	return &_data;
}
