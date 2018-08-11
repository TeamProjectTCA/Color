#pragma once
#include "smart_ptr.h"

PTR( ViewTurn );
PTR( ProcessorForServer );
PTR( Sheet );

class ViewTurn {
public:
	ViewTurn( ProcessorForServerConstPtr processor );
	virtual ~ViewTurn( );

public:
	void initialize( );

public:
	void updateSheet( );

public:
	SheetPtr getSheet( ) const;

private:
	ProcessorForServerConstPtr _processor;
	SheetPtr _sheet;
};

