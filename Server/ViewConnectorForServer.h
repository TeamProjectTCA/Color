#pragma once
#include "smart_ptr.h"

PTR( ViewConnectorForServer );
PTR( ConnectorForServer );
PTR( Sheet );

class ViewConnectorForServer {
public:
	ViewConnectorForServer( ConnectorForServerConstPtr connector );
	virtual ~ViewConnectorForServer( );

public:
	void updateSheet( );

public:
	SheetPtr getSheet( ) const;

private:
	ConnectorForServerConstPtr _connector;
	SheetPtr _sheet;
};

