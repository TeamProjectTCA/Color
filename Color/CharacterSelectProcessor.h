#pragma once
#include "smart_ptr.h"

PTR( TitleProcessor );
PTR( SceneManager );
PTR( Mouse );
PTR( Keyboard );

class CharacterSelectProcessor {
public:
	CharacterSelectProcessor( );
	virtual ~CharacterSelectProcessor( );

public:
	void update( );

private:
	SceneManagerPtr _scene_manager;
	KeyboardPtr _keyboard;
	MousePtr _mouse;
};