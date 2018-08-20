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
	void setPlayerIdx( int player_idx );

public:
	int getPlayerIdx( ) const;

private:
	int _player_idx;
};

