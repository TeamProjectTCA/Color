#pragma once
#include "smart_ptr.h"

PTR( ResultProcessor );
PTR( SceneManager );

class ResultProcessor {
public:
	ResultProcessor( );
	virtual ~ResultProcessor( );

public:
	void update( );
	void draw( ) const;

private:
	void countChange( );

private:
	int _timer;

	SceneManagerPtr _scene_manager;
};