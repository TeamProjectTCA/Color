#pragma once
#include "smart_ptr.h"
#include "Server.h"
#include <string>
#include <array>

PTR( ConnectorForServer );
PTR( Log );
PTR( Sheet );

class ConnectorForServer {
public:
	ConnectorForServer( LogPtr log );
	virtual ~ConnectorForServer( );

public:
	void update( );

private:
	void updateSheet( );

public:
	std::string getMachinesIp( int idx ) const;
	std::string getServerIp( ) const;
	
	SheetPtr getSheetServer( ) const;
	SheetPtr getSheetClient( ) const;

private:
	void checkConnect( );

private:
	std::array< std::string, Server::MAX_MACHINES > _machines;

	LogPtr _log;
	SheetPtr _sheet_server;
	SheetPtr _sheet_client;
};

