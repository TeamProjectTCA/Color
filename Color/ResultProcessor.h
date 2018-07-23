#pragma once
#include "smart_ptr.h"

PTR( ResultProcessor );
PTR( SceneManager );
PTR( Mouse );
PTR( Keyboard );

class ResultProcessor {
public:
	ResultProcessor( );
	virtual ~ResultProcessor( );

public:
	void update( );

private:
	SceneManagerPtr _scene_manager;
	KeyboardPtr _keyboard;
	MousePtr _mouse;
};