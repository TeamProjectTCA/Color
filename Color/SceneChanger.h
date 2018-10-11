#pragma once
#include "smart_ptr.h"
#include "Event.h"
#include "Scene.h"

PTR( SceneChanger );

class SceneChanger : public Event {
public:
	SceneChanger( SCENE next );
	virtual ~SceneChanger( );

public:
	void activate( );

private:
	SCENE _next;
};

