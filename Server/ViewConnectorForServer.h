#pragma once
#include "smart_ptr.h"

PTR( ConnectorForServer );
PTR( Sheet );

class ViewConnectorForServer {
public:
	ViewConnectorForServer( ConnectorForServerConstPtr connector );
	virtual ~ViewConnectorForServer( );

public:
	void updateSheet( );

public:
	SheetPtr getSheetServer( ) const;
	SheetPtr getSheetClient( ) const;

private:
	ConnectorForServerConstPtr _connector;
	SheetPtr _sheet_server;
	SheetPtr _sheet_client;
};

