#pragma once
#include "GameDrawer.h"
#include <array>

class PaintCount : public GameDrawer {
public:
	PaintCount( );
	virtual ~PaintCount( );

public:
	void draw( ) const;

public:
	void setPaintCount( int player_num, int paint_count );
	
private:
	std::array< int, 2 > _paint_count;
};