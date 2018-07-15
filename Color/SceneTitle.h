#pragma once
#include "Scene.h"
#include "smart_ptr.h"

PTR( SceneTitle );
PTR( Keyboard );
PTR( Mouse );

class SceneTitle : public Scene {
public:
	SceneTitle( );
	virtual ~SceneTitle( );

public:
	void initialize( );
	void update( );

private:
	int test;

	KeyboardPtr _keyboard;
	MousePtr _mouse;
};