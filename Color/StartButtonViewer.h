#pragma once
#include "smart_ptr.h"

PTR( StartButtonViewer );
PTR( StartButton );
PTR( Drawer );
PTR( Image );

class StartButtonViewer {
public:
	StartButtonViewer( StartButtonPtr start_button );
	virtual ~StartButtonViewer( );

public:
	void update( );

private:
	void drawNormalButton( ) const;
	void drawPushButton( ) const;

private:
	ImagePtr _normal_start_button;
	ImagePtr _push_start_button;

	DrawerPtr _drawer;
	StartButtonPtr _start_button;
};