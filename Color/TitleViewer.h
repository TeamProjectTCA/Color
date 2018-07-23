#pragma once
#include "smart_ptr.h"

PTR( TitleViewer );
PTR( TitleProcessor );
PTR( Drawer );
PTR( Image );

class TitleViewer {
public:
	TitleViewer( TitleProcessorPtr title );
	virtual ~TitleViewer( );

public:
	void update( );

private:
	void drawTitleLogo( ) const;
	void drawBackGround( ) const;

private:
	ImagePtr _bg_image;
	ImagePtr _title_image;

	DrawerPtr _drawer;
	TitleProcessorPtr _scene_title;
};