#pragma once
#include "Scene.h"
#include "smart_ptr.h"

PTR( ViewSceneCharacterSelect );
PTR( SceneCharacterSelect );
PTR( Drawer );

class ViewSceneCharacterSelect : public Scene {
public:
	ViewSceneCharacterSelect( SceneCharacterSelectPtr character_select );
	virtual ~ViewSceneCharacterSelect( );

public:
	void update( );

private:
	DrawerPtr _drawer;
	SceneCharacterSelectPtr _scene_character_select;
};