#pragma once
#include "smart_ptr.h"

PTR( CommandListener );
PTR( CommandWord );

class CommandListener {
public:
	CommandListener( );
	virtual ~CommandListener( );

public:
	virtual void command( CommandWordConstPtr word ) = 0;
};

