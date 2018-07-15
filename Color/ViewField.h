#pragma once
#include <array>
#include "smart_ptr.h"

PTR( ViewField );
PTR( Drawer );

class ViewField {
public:
	ViewField( );
	virtual ~ViewField( );

public:
	void update( );

private:
	void drawField( ) const;

private:
	DrawerPtr _drawer;

	std::array< int, 2 > _mas_handle;
};

