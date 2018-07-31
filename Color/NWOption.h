#pragma once
#include "Scene.h"

PTR( NWOption );

class NWOption : public Scene {
public:
	NWOption( );
	virtual ~NWOption( );

public:
	void update( );
};

