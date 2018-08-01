#pragma once
#include "Scene.h"
#include "smart_ptr.h"

PTR( GameViewer );
PTR( GameProcessor );
PTR( ViewField );
PTR( ViewPlayerUI );
PTR( ViewChara );

class GameViewer {
public:
	GameViewer( GameProcessorConstPtr processor );
	virtual ~GameViewer( );

public:
	void update( );

private:
	ViewFieldPtr _field;
	ViewPlayerUIPtr _player0_ui;
	ViewPlayerUIPtr _player1_ui;
	ViewCharaPtr _player0;
	ViewCharaPtr _player1;
};