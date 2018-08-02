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

std::string ServerToClientDataTcp::getIP( int idx ) const {
	std::string result;
	ServerToClientDataTcp::Pack::IP ip = _data.player.data[ idx ].ip;
	result += std::to_string( ip.d1 );
	result += ".";
	result += std::to_string( ip.d2 );
	result += ".";
	result += std::to_string( ip.d3 );
	result += ".";
	result += std::to_string( ip.d4 );
	return result;
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
