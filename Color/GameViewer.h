#pragma once
#include "Scene.h"
#include "smart_ptr.h"

PTR( GameViewer );
PTR( FieldViewer );
PTR( GameProcessor );
PTR( Drawer );

class GameViewer {
public:
	GameViewer( GameProcessorPtr game );
	virtual ~GameViewer( );

public:
	void update( );


private:
	DrawerPtr _drawer;
	GameProcessorPtr _scene_game;
	FieldViewerPtr _view_field;

};