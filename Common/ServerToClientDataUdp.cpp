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

void ServerToClientDataUdp::setTileState( int x, int y, FieldProperty::TILE_STATE state ) {
	_data.tile_state[ y ][ x ] = ( unsigned char )state;
}

void ServerToClientDataUdp::setPaintCount( int idx, int paint_count ) {
	_data.player[ idx ].paint_count = ( unsigned char ) paint_count;
}

Vector ServerToClientDataUdp::getPlayerPos( int idx ) const {
	Vector pos = Vector( _data.player[ idx ].x, _data.player[ idx ].y );
	return pos;
}

int ServerToClientDataUdp::getTurn( ) const {
	return _data.turn;
}

FieldProperty::TILE_STATE ServerToClientDataUdp::getTileState( int x, int y ) const {
	return ( FieldProperty::TILE_STATE )_data.tile_state[ y ][ x ];
}

int ServerToClientDataUdp::getPaintCount( int idx ) const {
	return _data.player[ idx ].paint_count;
}

int ServerToClientDataUdp::getSize( ) const {
	return sizeof( _data );
}

void* ServerToClientDataUdp::getPtr( ) {
	return &_data;
}
