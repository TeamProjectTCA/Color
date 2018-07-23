#pragma once
#include "smart_ptr.h"

PTR( ViewerForServer );
PTR( ProcessorForServer );

class ViewerForServer {
public:
	ViewerForServer( ProcessorForServerConstPtr processor );
	virtual ~ViewerForServer( );
};

