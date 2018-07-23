#pragma once
#include "smart_ptr.h"

PTR( Scene );

enum SCENE {
	SCENE_CONTINUE,
	SCENE_TITLE,
	SCENE_CHARACTERSELECT,
	SCENE_GAME,
	SCENE_RESULT,
	SCENE_SCENE_MAX,
};

class Scene {
public:
	Scene( );
	virtual ~Scene( );

public:
	virtual void update( ) = 0;
	void setNextScene( SCENE next_scene );
	SCENE getNextScene( ) const;

private:
	SCENE _next_scene;
};