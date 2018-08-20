#pragma once
#include "Data.h"
#include "smart_ptr.h"
#include "Vector.h"

PTR( ClientToServerData );

class ClientToServerData : public Data {
public:
	enum DATA_TYPE {
		DATA_TYPE_PLAYER,
	};

public:
	ClientToServerData( );
	virtual ~ClientToServerData( );

public:
	void setClickMas( Vector mas_idx );
	void setPlayerIdx( int idx );

public:
	unsigned char getDataType( ) const;
	Vector getClickMas( ) const;
	int getPlayerIdx( ) const;

public:
	int getSize( ) const;
	void *getPtr( );

private:
	#pragma pack( 1 )

	struct Pack {
		struct ClickMas {
			unsigned char x;
			unsigned char y;
		};

		// union Œ^ //
		struct Player {
			unsigned char player_idx;
			ClickMas mas;
		};


		unsigned char data_type;
		union {
			Player player;
		};
	};

	#pragma pack( )

	Pack _data;
};

