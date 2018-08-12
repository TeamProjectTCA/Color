#include "ClientToServerData.h"

ClientToServerData::ClientToServerData( ) {
	_data = Pack( );
}

ClientToServerData::~ClientToServerData( ) {
}

void ClientToServerData::setClickMas( Vector mas_idx ) {
	_data.mas_idx.x = ( unsigned char ) mas_idx.x;
	_data.mas_idx.y = ( unsigned char ) mas_idx.y;
}

void ClientToServerData::setPlayerNum( int num ) {
	_data.player_num = num;
}

Vector ClientToServerData::getClickMas( ) const {
	Vector mas = Vector( _data.mas_idx.x, _data.mas_idx.y );
	return mas;
}

int ClientToServerData::getPlayerNum( ) const {
	return _data.player_num;
}

int ClientToServerData::getSize( ) const {
	return sizeof( _data );
}

void* ClientToServerData::getPtr( ) {
	return &_data;
}
