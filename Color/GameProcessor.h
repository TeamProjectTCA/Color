#pragma once
#include "smart_ptr.h"

PTR( GameProcessor );
PTR( SceneManager );
PTR( Mouse );
PTR( Keyboard );

class GameProcessor {
public:
	GameProcessor( );
	virtual ~GameProcessor( );

public:
	void update( );

private:
	SceneManagerPtr _scene_manager;
	KeyboardPtr _keyboard;
	MousePtr _mouse;
};
