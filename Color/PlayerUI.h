#pragma once
#include "Area.h"

class PlayerUI : public Area {
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

