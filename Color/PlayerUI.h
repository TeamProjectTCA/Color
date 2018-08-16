#pragma once
#include "Area.h"
#include <array>

class PlayerUI : public Area {
public:
	PlayerUI( const Vector ORIGIN_POS );
	virtual ~PlayerUI( );

public:
	void draw( ) const;
	
public:
	void setPaintCount( int paint_count );

public:
	Vector getPlayerImagePos( ) const;

private:
	bool _full_hd;
	int _paint_count;
};