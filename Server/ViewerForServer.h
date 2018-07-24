#pragma once
#include "smart_ptr.h"

PTR( ViewerForServer );
PTR( ProcessorForServer );
PTR( Table );
PTR( Log );

class ViewerForServer {
public:
	ViewerForServer( ProcessorForServerConstPtr processor, LogConstPtr log );
	virtual ~ViewerForServer( );

public:
	void update( );

private:
	TablePtr _table;
};

