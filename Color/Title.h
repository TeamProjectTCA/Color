#pragma once
#include "Scene.h"
#include "smart_ptr.h"

PTR( Title );
PTR( TitleProcessor );
PTR( Viewer );

class Title : public Scene {
public:
	Title( ViewerPtr viewer );
	virtual ~Title( );

public:
	void update( );

private:
	TitleProcessorPtr _process;
};