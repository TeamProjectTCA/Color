#pragma once
#include "Scene.h"
#include "smart_ptr.h"

PTR( Title );
PTR( TitleProcessor );
PTR( TitleViewer );

class Title : public Scene {
public:
	Title( );
	virtual ~Title( );

public:
	void update( );

private:
	TitleProcessorPtr _process;
	TitleViewerPtr _viewer;
};