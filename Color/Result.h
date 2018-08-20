#pragma once
#include "Scene.h"
#include "smart_ptr.h"

PTR( Result );
PTR( ResultProcessor );
PTR( Viewer );

class Result : public Scene {
public:
	Result( ViewerPtr viewer );
	virtual ~Result( );

public:
	void update( );

private:
	ResultProcessorPtr _process;
};