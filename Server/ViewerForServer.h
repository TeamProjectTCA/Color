#pragma once
#include "smart_ptr.h"

PTR( Table );

class ViewerForServer {
public:
	ViewerForServer( TableConstPtr table );
	virtual ~ViewerForServer( );

public:
	void update( );

private:
	TableConstPtr _table;
};

