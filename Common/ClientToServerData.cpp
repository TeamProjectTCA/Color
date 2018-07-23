#include "ClientToServerData.h"

ClientToServerData::ClientToServerData( ) {
	_data = Pack( );
}

ClientToServerData::~ClientToServerData( ) {
}

int ClientToServerData::getSize( ) const {
	return sizeof( _data );
}

void* ClientToServerData::getPtr( ) {
	return &_data;
}
