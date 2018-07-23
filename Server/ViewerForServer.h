#pragma once
#include "smart_ptr.h"

PTR( ViewerForServer );
PTR( ProcessorForServer );
PTR( Table );

class ViewerForServer {
public:
	ViewerForServer( ProcessorForServerConstPtr processor );
	virtual ~ViewerForServer( );

public:
	void update( );

private:
	TablePtr _table;
};

