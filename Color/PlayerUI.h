#pragma once
#include "Area.h"
#include "GameDrawer.h"

class PlayerUI : public Area, public GameDrawer {
public:
	PlayerUI( const Vector ORIGIN_POS );
	virtual ~PlayerUI( );

public:
	void draw( ) const;

public:
	Vector getPlayerImagePos( ) const;

private:
	bool _full_hd;
};

