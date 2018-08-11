#pragma once
#include "Data.h"
#include "smart_ptr.h"
#include "Vector.h"

PTR( ClientToServerData );

class ClientToServerData : public Data {
public:
	ClientToServerData( );
	virtual ~ClientToServerData( );

public:
	void setClickMas( Vector mas_idx );

public:
	Vector getClickMas( ) const;

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
		ClickMas mas_idx;
	};

	#pragma pack( )

	Pack _data;
};

