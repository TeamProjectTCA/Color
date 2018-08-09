#pragma once
#include "smart_ptr.h"
#include "Event.h"
#include "Scene.h"

PTR( SceneChanger );

class SceneChanger : public Event {
public:
	SceneChanger( SCENE scene );
	virtual ~SceneChanger( );

public:
	void onEvent( );

private:
	SCENE _scene;
};

