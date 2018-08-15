#include "ClientToServerData.h"

ClientToServerData::ClientToServerData( ) {
	_data = Pack( );
}

ClientToServerData::~ClientToServerData( ) {
}

void ClientToServerData::setClickMas( Vector mas_idx ) {
	_data.data_type = DATA_TYPE_PLAYER;
	_data.player.mas.x = ( unsigned char )mas_idx.x;
	_data.player.mas.y = ( unsigned char )mas_idx.y;
}

void ClientToServerData::setPlayerNum( int num ) {
	_data.data_type = DATA_TYPE_PLAYER;
	_data.player.player_num = ( unsigned char )num;
}

unsigned char ClientToServerData::getDataType( ) const {
	return _data.data_type;
}

Vector ClientToServerData::getClickMas( ) const {
	Vector mas = Vector( _data.player.mas.x, _data.player.mas.y );
	return mas;
}

int ClientToServerData::getPlayerNum( ) const {
	return ( int )_data.player.player_num;
}

int ClientToServerData::getSize( ) const {
	return sizeof( _data );
}

void* ClientToServerData::getPtr( ) {
	return &_data;
}
