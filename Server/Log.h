#pragma once
#include "smart_ptr.h"
#include <string>
#include <array>

PTR( Log );

class Log {
public:
	Log( );
	virtual ~Log( );

public:
	void add( std::string log );

public:
	int getRow( ) const;
	std::string getLog( int idx ) const;

private:
	static const int ROW = 25;
	std::array< std::string, ROW > _log;
};

