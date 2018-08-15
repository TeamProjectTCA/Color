#pragma once
#include "smart_ptr.h"
#include <list>

PTR( GameDrawer );

class Viewer {
public:
	Viewer( );
	virtual ~Viewer( );

public:
	void update( );

public:
	void resetDrawer( );
	void addDrawer( GameDrawerConstPtr drawer );

private:
	std::list< GameDrawerConstPtr > _drawer;
};

