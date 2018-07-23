#pragma once
#include "Data.h"
#include "smart_ptr.h"

PTR( ClientToServerData );

class ClientToServerData : public Data {
public:
	ClientToServerData( );
	virtual ~ClientToServerData( );

public:
	int getSize( ) const;
	void *getPtr( );

private:
	#pragma pack( 1 )

	struct Pack {
		unsigned char a;
	};

	#pragma pack( )

	Pack _data;
};

