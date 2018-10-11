#pragma once
#include "smart_ptr.h"

PTR( Scene );

enum SCENE {
	SCENE_CONTINUE,
	SCENE_TITLE,
	SCENE_NWOPTION,
	SCENE_CHARACTERSELECT,
	SCENE_GAME,
	SCENE_RESULT,
};

class Scene {
public:
	Scene( );
	virtual ~Scene( );

public:
	void onUpdate( );

private:
	virtual void update( ) = 0;
	virtual void draw( ) const = 0;
};