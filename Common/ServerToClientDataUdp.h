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
	void setPlayer0Pos( Vector pos );
	void setPlayer1Pos( Vector pos );

public:
	Vector getPlayer0Pos( ) const;
	Vector getPlayer1Pos( ) const;

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

		Player player0;
		Player player1;
	};

	#pragma pack( )

	Pack _data;
};

