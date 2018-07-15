#pragma once
#include "Scene.h"
#include "smart_ptr.h"

PTR( ViewSceneResult );
PTR( SceneResult );
PTR( Drawer );

class ViewSceneResult : public Scene {
public:
	ViewSceneResult( SceneResultPtr result );
	virtual ~ViewSceneResult( );

public:
	void update( );

private:
	DrawerPtr _drawer;
	SceneResultPtr _scene_result;
};

