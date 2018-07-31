#pragma once
#include "smart_ptr.h"

PTR( OptionButtonViewer );
PTR( OptionButton );
PTR( Drawer );
PTR( Image );

class OptionButtonViewer {
public:
	OptionButtonViewer( OptionButtonPtr option_button );
	virtual ~OptionButtonViewer( );

public:
	void update( );

private:
	void drawNormalButton( ) const;
	void drawPushButton( ) const;

private:
	ImagePtr _normal_option_button;
	ImagePtr _push_option_button;

	DrawerPtr _drawer;
	OptionButtonPtr _option_button;
};