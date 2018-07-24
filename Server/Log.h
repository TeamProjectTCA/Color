#pragma once
#include "smart_ptr.h"
#include <string>

PTR( Log );
PTR( Sheet );

class Log {
public:
	Log( );
	virtual ~Log( );

public:
	void add( std::string log );
	SheetPtr getSheet( ) const;

private:
	SheetPtr _sheet;
};

