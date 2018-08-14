#pragma once
#include "smart_ptr.h"
#include "Vector.h"
#include "GameDrawer.h"
#include <vector>

PTR( TitleProcessor );
PTR( Button );
PTR( Image );

class TitleProcessor : public GameDrawer {
public:
	TitleProcessor( );
	virtual ~TitleProcessor( );

public:
	void update( );
	void draw( ) const;

private:
	ImagePtr _bg;
	ImagePtr _logo;
	std::vector< ButtonPtr > _button;
};