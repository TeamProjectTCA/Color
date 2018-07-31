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
	TitleViewer( TitleProcessorPtr title, StartButtonViewerPtr button, OptionButtonViewerPtr option_button );
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
	StartButtonViewerPtr _view_start_button;
	OptionButtonViewerPtr _view_option_button;
};