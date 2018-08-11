#pragma once
#include "smart_ptr.h"

PTR( TitleViewer );
PTR( TitleProcessor );
PTR( StartButtonViewer );
PTR( OptionButtonViewer );
PTR( Drawer );
PTR( Image );

class TitleViewer {
public:
	TitleViewer( TitleProcessorConstPtr processor );
	virtual ~TitleViewer( );

public:
	void update( );

private:
	void drawTitleLogo( ) const;
	void drawBackGround( ) const;
	void drawButton( ) const;

private:
	ImagePtr _bg_image;
	ImagePtr _title_image;

	DrawerPtr _drawer;
	TitleProcessorConstPtr _processor;
};