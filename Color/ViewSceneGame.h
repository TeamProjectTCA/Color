#pragma once
#include "Scene.h"
#include "smart_ptr.h"

PTR( ViewSceneGame );
PTR( ViewField );
PTR( SceneGame );
PTR( Drawer );

class ViewSceneGame : public Scene {
public:
	ViewSceneGame( SceneGamePtr game );
	virtual ~ViewSceneGame( );

public:
	void update( );


private:
	DrawerPtr _drawer;
	SceneGamePtr _scene_game;
	ViewFieldPtr _view_field;

};

