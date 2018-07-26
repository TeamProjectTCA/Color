#pragma once
#include "smart_ptr.h"

PTR( ViewCommand );
PTR( Command );
PTR( Sheet );

class ViewCommand {
public:
	ViewCommand( CommandConstPtr command );
	virtual ~ViewCommand( );

public:
	void updataSheet( );

public:
	SheetPtr getSheet( ) const;

private:
	CommandConstPtr _command;
	SheetPtr _sheet;
};

