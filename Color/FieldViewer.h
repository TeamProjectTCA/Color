#pragma once
#include <array>
#include "smart_ptr.h"

PTR( FieldViewer );
PTR( Drawer );
PTR( Image );

class FieldViewer {
public:
	FieldViewer( );
	virtual ~FieldViewer( );

public:
	void update( );

private:
	void drawField( ) const;

private:
	DrawerPtr _drawer;

	std::array< ImagePtr, 2 > _mas_handle;
};

