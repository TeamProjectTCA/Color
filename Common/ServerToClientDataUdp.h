#pragma once
#include "Data.h"
#include "smart_ptr.h"
#include "Vector.h"

PTR( ServerToClientDataUdp );

class ServerToClientDataUdp : public Data {
public:
	ServerToClientDataUdp( );
	virtual ~ServerToClientDataUdp( );

public:
	void setPlayerPos( int idx, Vector pos );

public:
	Vector getPlayerPos( int idx ) const;

public:
	int getSize( ) const;
	void *getPtr( );

private:
	#pragma pack( 1 )

	struct Pack {
		struct Player {
			unsigned char x;
			unsigned char y;
		};

		Player player[ 2 ];
	};

	#pragma pack( )

	Pack _data;
};

