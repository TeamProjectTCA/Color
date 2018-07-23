#pragma once
#include "Scene.h"
#include "smart_ptr.h"

PTR( Game );
PTR( GameProcessor );
PTR( GameViewer );

class Game : public Scene {
public:
	Game( );
	~Game( );

public:
	void update( );

private:
	GameProcessorPtr _process;
	GameViewerPtr _viewer;
};