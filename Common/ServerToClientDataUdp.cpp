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

void ServerToClientDataUdp::setColor( std::array< std::array< int, FieldProperty::FIELD_COL >, FieldProperty::FIELD_ROW > color ) {
	_data.color = color;
}

void ServerToClientDataUdp::setPaintCount( int idx, int paint_count ) {
	_data.player[ idx ].paint_count = paint_count;
}

Vector ServerToClientDataUdp::getPlayerPos( int idx ) const {
	Vector pos = Vector( _data.player[ idx ].x, _data.player[ idx ].y );
	return pos;
}

int ServerToClientDataUdp::getTurn( ) const {
	return _data.turn;
}

std::array< std::array< int, FieldProperty::FIELD_COL >, FieldProperty::FIELD_ROW > ServerToClientDataUdp::getColor( ) const {
	return _data.color;
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
