#pragma once
#include "smart_ptr.h"
#include <string>
#include <array>

PTR( Log );
PTR( Sheet );

class Log {
public:
	Log( );
	virtual ~Log( );

private:
	void updateSheet( );

public:
	void add( std::string log );

public:
	int getRow( ) const;
	SheetPtr getSheet( ) const;

private:
	static const int ROW = 25;

private:
	std::array< std::string, ROW > _log;
	SheetPtr _sheet;
};