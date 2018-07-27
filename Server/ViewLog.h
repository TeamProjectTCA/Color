#pragma once
#include "smart_ptr.h"

PTR( ViewLog );
PTR( Log );
PTR( Sheet );

class ViewLog {
public:
	ViewLog( LogConstPtr log );
	virtual ~ViewLog( );

public:
	void initialize( );

public:
	void updateSheet( );
	SheetPtr getSheet( ) const;

private:
	SheetPtr _sheet;
	LogConstPtr _log;
};

