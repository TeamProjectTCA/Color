#pragma once
#include "Scene.h"
#include "smart_ptr.h"

PTR ( ViewSceneGame );
PTR ( SceneGame );
PTR ( Keyboard );
PTR ( Mouse );

class SceneGame : public Scene {
public:
	SceneGame ( );
	~SceneGame ( );

public:
	void initialize ( );
	void update ( );

private:
	MousePtr _mouse;
	KeyboardPtr _keyboard;
	ViewSceneGamePtr _view_game;
};

