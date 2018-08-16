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
	void setColor( std::array< std::array< int, FieldProperty::FIELD_COL >, FieldProperty::FIELD_ROW > color );
	void setPaintCount( int idx, int paint_count );

public:
	Vector getPlayerPos( int idx ) const;
	int getTurn( ) const;
	std::array< std::array< int, FieldProperty::FIELD_COL >, FieldProperty::FIELD_ROW > getColor( ) const;
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
			int paint_count;
		};

		Player player[ 2 ];
		int turn;
		std::array< std::array< int, FieldProperty::FIELD_COL >, FieldProperty::FIELD_ROW > color;
	};

	#pragma pack( )

	Pack _data;
};

