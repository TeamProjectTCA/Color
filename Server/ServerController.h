#pragma once
#include "Base.h"
#include "smart_ptr.h"
#include <string>

PTR( ServerController );
PTR( ClientToServerData );
PTR( NWManagerForServer );
PTR( ProcessorForServer );
PTR( ViewerForServer );
PTR( Table );

class ServerController : public Base {
public:
	static ServerControllerPtr getTask( );
	static std::string getTag( ) { return "SERVER_CONTROLLER"; }

public:
	ServerController( ClientToServerDataConstPtr recvdata );
	virtual ~ServerController( );

public:
	void initialize( );
	void update( );

private:
	NWManagerForServerPtr _network;
	ProcessorForServerPtr _processor;
	ClientToServerDataConstPtr _recvdata;
	ViewerForServerPtr _viewer;
};

