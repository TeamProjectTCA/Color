#include "ServerToClientDataUdp.h"

ServerToClientDataUdp::ServerToClientDataUdp( ) {
	_data = Pack( );
}

ServerToClientDataUdp::~ServerToClientDataUdp( ) {
}

int ServerToClientDataUdp::getSize( ) const {
	return sizeof( _data );
}

void* ServerToClientDataUdp::getPtr( ) {
	return &_data;
}
