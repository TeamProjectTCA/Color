#pragma once
#include "Chara.h"
#include "smart_ptr.h"

PTR( User );
PTR( Field );

class User : public Chara {
public:
	User( FieldConstPtr field );
	virtual ~User( );

public:
	void update( );

public:
	void setPlayerNum( int player_num );

private:
	int _player_num;
};

