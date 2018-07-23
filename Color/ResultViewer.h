#pragma once
#include "Scene.h"
#include "smart_ptr.h"

PTR( ResultViewer );
PTR( ResultProcessor );
PTR( Drawer );

class ResultViewer {
public:
	ResultViewer( ResultProcessorPtr result );
	virtual ~ResultViewer( );

public:
	void update( );

private:
	DrawerPtr _drawer;
	ResultProcessorPtr _scene_result;
};