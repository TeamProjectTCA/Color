#pragma once
#include "Data.h"
#include "smart_ptr.h"
#include "Vector.h"
#include "FieldProperty.h"
#include <array>

PTR( ServerToClientDataUdp );

class ServerToClientDataUdp : public Data {
public:
	ServerToClientDataUdp( );
	virtual ~ServerToClientDataUdp( );

public:
	void setPlayerPos( int idx, Vector pos );
	void setTurn( int turn );
	void setTileState( int x, int y, FieldProperty::TILE_STATE state );
	void setPaintCount( int idx, int paint_count );

public:
	Vector getPlayerPos( int idx ) const;
	int getTurn( ) const;
	FieldProperty::TILE_STATE getTileState( int x, int y ) const;
	int getPaintCount( int idx ) const;

public:
	int getSize( ) const;
	void *getPtr( );

private:
	#pragma pack( 1 )

	struct Pack {
		struct Player {
			unsigned char x;
			unsigned char y;
			unsigned char paint_count;
		};

		Player player[ 2 ];
		unsigned char turn;
		unsigned char tile_state[ FieldProperty::FIELD_ROW ][ FieldProperty::FIELD_COL ];
	};

	#pragma pack( )

	Pack _data;
};

