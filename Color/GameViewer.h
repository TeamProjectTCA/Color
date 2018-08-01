#pragma once
#include "Scene.h"
#include "smart_ptr.h"

PTR( GameViewer );
PTR( GameProcessor );
PTR( ViewField );
PTR( ViewPlayerUI );

class GameViewer {
public:
	GameViewer( GameProcessorConstPtr processor );
	virtual ~GameViewer( );

public:
	void update( );

private:
	ViewFieldPtr _field;
	ViewPlayerUIPtr _player1_ui;
	ViewPlayerUIPtr _player2_ui;
};