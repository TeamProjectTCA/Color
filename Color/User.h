#pragma once
#include "Chara.h"
#include "smart_ptr.h"
#include "GameDrawer.h"

PTR( User );
PTR( Field );

class User : public Chara {
public:
	User( FieldConstPtr field );
	virtual ~User( );

public:
	void update( );
	void draw( ) const;

public:
	void setPlayerNum( int player_num );

public:
	int getPlayerNum( ) const;

private:
	int _player_num;
};

