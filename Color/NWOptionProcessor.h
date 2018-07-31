#pragma once
#include "smart_ptr.h"
#include <string>

PTR( NWOptionProcessor );

class NWOptionProcessor {
public:
	NWOptionProcessor( );
	virtual ~NWOptionProcessor( );

public:
	void update( );

private:
	void write( );

private:
	std::string _ip;
	std::string _new_ip;
};

