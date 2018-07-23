#pragma once
#include "Data.h"
#include "smart_ptr.h"

PTR( ServerToClientDataUdp );

class ServerToClientDataUdp : public Data {
public:
	ServerToClientDataUdp( );
	virtual ~ServerToClientDataUdp( );

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

