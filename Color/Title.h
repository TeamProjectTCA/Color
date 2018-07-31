#pragma once
#include "Scene.h"
#include "smart_ptr.h"

PTR( Title );
PTR( TitleProcessor );
PTR( TitleViewer );
PTR( StartButton );
PTR( StartButtonViewer );
PTR( OptionButton );
PTR( OptionButtonViewer );

class Title : public Scene {
public:
	Title( );
	virtual ~Title( );

public:
	void update( );

private:
	TitleProcessorPtr _process;
	TitleViewerPtr _viewer;
	StartButtonPtr _start_button;
	StartButtonViewerPtr _view_start_button;
	OptionButtonPtr _option_button;
	OptionButtonViewerPtr _view_option_button;
};