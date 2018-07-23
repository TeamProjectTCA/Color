#pragma once
#include "smart_ptr.h"
#include "Vector.h"

PTR( TitleProcessor );
PTR( SceneManager );
PTR( Mouse );
PTR( Keyboard );

class TitleProcessor {
public:
	TitleProcessor( );
	virtual ~TitleProcessor( );

public:
	void update( );

public:
	Vector getBgPos( );
	Vector getLogoPos( );

private:
	Vector _bg_pos;
	Vector _logo_pos;

	SceneManagerPtr _scene_manager;
	KeyboardPtr _keyboard;
	MousePtr _mouse;
};