#pragma once
#include "Scene.h"
#include "smart_ptr.h"

PTR( SceneResult );
PTR( Keyboard );
PTR( Mouse );

class SceneResult : public Scene {
public:
	SceneResult( );
	virtual ~SceneResult( );

public:
	void initialize( );
	void update( );

private:
	MousePtr _mouse;
	KeyboardPtr _keyboard;
};

