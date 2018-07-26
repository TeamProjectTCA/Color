#pragma once
#include "smart_ptr.h"
#include "Client.h"
#include "SceneManager.h"
#include <string>
#include <array>

PTR( Connector );
PTR( SceneManager );

class Connector {
public:
	Connector( );
	virtual ~Connector( );

public:
	void initialize( );
	void update( );

private:
	void checkConnect( );

private:
	SceneManagerPtr _scene_manager;
};

