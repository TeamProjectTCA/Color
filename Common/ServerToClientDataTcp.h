#pragma once
#include "Data.h"
#include "smart_ptr.h"
#include "Vector.h"
#include <string>

PTR( ServerToClientDataTcp );

class ServerToClientDataTcp : public Data {
public:
	static const unsigned char DATA_TYPE_PLAYER = 0x01;
	static const unsigned char DATA_TYPE_RESULT = 0x02;

public:
	ServerToClientDataTcp( );
	virtual ~ServerToClientDataTcp( );

public:
	void setIP( int idx, std::string ip );
	void setGameOver( bool gameover );
public:
	int getIdx( std::string ip ) const;
	bool getGameOver( ) const;
	unsigned char getType( ) const;

public:
	int getSize( ) const;
	void *getPtr( );

private:
#pragma pack( 1 )

	struct Pack {
		struct IP {
			unsigned char d1;
			unsigned char d2;
			unsigned char d3;
			unsigned char d4;
		};

		struct PlayerData {
			IP ip;
		};

		struct Player {
			PlayerData data[ 2 ];
		};

		struct Result {
			bool gameover;
		};

		unsigned char type;

		union {
			Player player;
			Result result;
		};
	};

#pragma pack( )
	Pack _data;
};