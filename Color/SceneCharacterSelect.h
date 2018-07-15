#pragma once
#include "Scene.h"
#include "smart_ptr.h"

PTR( SceneCharacterSelect );
PTR( Keyboard );
PTR( Mouse );

class SceneCharacterSelect : public Scene {
public:
	SceneCharacterSelect( );
	virtual ~SceneCharacterSelect( );

public:
	void initialize( );
	void update( );

private:
	MousePtr _mouse;
	KeyboardPtr _keyboard;
};

