#pragma once
#include "smart_ptr.h"
#include <string>

PTR( Connector );

class Connector {
public:
	Connector( );
	virtual ~Connector( );

public:
	void update( );

private:
	void checkConnect( );

private:
	std::string _past_state;
};

