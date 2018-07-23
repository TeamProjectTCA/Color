#pragma once
#include "Scene.h"
#include "smart_ptr.h"

PTR( Result );
PTR( ResultProcessor );
PTR( ResultViewer );

class Result : public Scene {
public:
	Result( );
	virtual ~Result( );

public:
	void update( );

private:
	ResultProcessorPtr _process;
	ResultViewerPtr _viewer;
};