#pragma once
#include "Scene.h"
#include "smart_ptr.h"

PTR( Result );
PTR( ResultProcessor );
PTR( Viewer );

class Result : public Scene {
public:
	Result( );
	virtual ~Result( );

public:
	void update( );
	void draw( ) const;
};