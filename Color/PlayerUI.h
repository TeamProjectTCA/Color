#pragma once
#include "Area.h"

class PlayerUI : public Area {
public:
	PlayerUI( const Vector ORIGIN_POS );
	virtual ~PlayerUI( );

public:
	Vector getPlayerImagePos( ) const;
};

