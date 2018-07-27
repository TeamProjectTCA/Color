#include "ProcessorForServer.h"
#include "ServerToClientDataUdp.h"
#include "Command.h"
#include "Test.h"

ProcessorForServer::ProcessorForServer( ServerToClientDataUdpPtr senddata_udp, LogPtr log, CommandPtr command ) :
_senddata_udp( senddata_udp ),
_command( command ) {
	TestPtr test( new Test( ) );
	_command->addListener( test );
}

ProcessorForServer::~ProcessorForServer( ) {
}

void ProcessorForServer::update( ) {
	_command->update( );
}