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
	ViewPlayerUIPtr _user_ui;
	ViewPlayerUIPtr _enemy_ui;
	ViewCharaPtr _user;
	ViewCharaPtr _enemy;
	GameProcessorConstPtr _processor;
};