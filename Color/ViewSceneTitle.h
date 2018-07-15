#pragma once
#include "Scene.h"
#include "smart_ptr.h"

PTR( ViewSceneTitle );
PTR( SceneTitle );
PTR( Drawer );

class ViewSceneTitle : public Scene {
public:
	ViewSceneTitle( SceneTitlePtr title );
	virtual ~ViewSceneTitle( );

public:
	void update( );

private:
	void drawTitleLogo( ) const;
	void drawBackGround( ) const;

private:
	int _bg_image;
	int _title_image;

	DrawerPtr _drawer;
	SceneTitlePtr _scene_title;
};

