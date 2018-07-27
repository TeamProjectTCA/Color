#pragma once
#include "CommandListener.h"
#include "smart_ptr.h"

PTR( Test );
PTR( CommandWord );

class Test:
	public CommandListener
{
public:
	Test();
	virtual ~Test();

public:
	CommandListener::RESULT command( CommandWordConstPtr word );
};

