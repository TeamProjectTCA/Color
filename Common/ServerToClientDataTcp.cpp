#include "ServerToClientDataTcp.h"

ServerToClientDataTcp::ServerToClientDataTcp( ) {
	_data = Pack( );
}

ServerToClientDataTcp::~ServerToClientDataTcp( ) {
}

void ServerToClientDataTcp::setIP( int idx, std::string ip ) {
	_data.type = DATA_TYPE_PLAYER;
	ServerToClientDataTcp::Pack::IP change = ServerToClientDataTcp::Pack::IP( );
	const int MAX_IDX = 4;
	unsigned char num[ MAX_IDX ] = { };
	for ( int i = 0; i < MAX_IDX; i++ ) {
		size_t pos = ip.find_first_of( '.' );
		if ( pos == std::string::npos && i != MAX_IDX - 1 ) {
			break;
		}
		num[ i ] = std::atoi( ip.substr( 0, pos ).c_str( ) );
		ip = ip.substr( pos + 1, ip.length( ) - pos - 1 );
	}
	change.d1 = num[ 0 ];
	change.d2 = num[ 1 ];
	change.d3 = num[ 2 ];
	change.d4 = num[ 3 ];
	_data.player.data[ idx ].ip = change;
}

void ServerToClientDataTcp::setGameOver( bool gameover ) {
	_data.type = DATA_TYPE_RESULT;
	_data.result.gameover = gameover;
}

int ServerToClientDataTcp::getIdx( std::string ip ) const {
	int idx = -1;
	for ( int i = 0; i < 2; i++ ) {
		ServerToClientDataTcp::Pack::IP ip_data = _data.player.data[ i ].ip;
		std::string result;
		result += std::to_string( ip_data.d1 );
		result += ".";
		result += std::to_string( ip_data.d2 );
		result += ".";
		result += std::to_string( ip_data.d3 );
		result += ".";
		result += std::to_string( ip_data.d4 );

		if ( result == ip ) {
			idx = i;
			break;
		}
	}
	return idx;
}

bool ServerToClientDataTcp::getGameOver( ) const {
	return _data.result.gameover;
}

unsigned char ServerToClientDataTcp::getType( ) const {
	return _data.type;
}

int ServerToClientDataTcp::getSize( ) const {
	return sizeof( _data );
}

void* ServerToClientDataTcp::getPtr( ) {
	return &_data;
}
