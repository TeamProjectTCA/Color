#pragma once
#include "smart_ptr.h"
#include "Server.h"
#include <string>
#include <array>

PTR( ConnectorForServer );
PTR( Log );

class ConnectorForServer {
public:
	ConnectorForServer( LogPtr log );
	virtual ~ConnectorForServer( );

public:
	void update( );

public:
	std::string getMachinesIp( int idx ) const;
	std::string getServerIp( ) const;

private:
	void checkConnect( );

private:
	std::array< std::string, Server::MAX_MACHINES > _machines;

	LogPtr _log;
};

