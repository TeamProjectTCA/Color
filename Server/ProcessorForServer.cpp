#include "ProcessorForServer.h"
#include "ServerToClientDataUdp.h"
#include "Command.h"

ProcessorForServer::ProcessorForServer( ServerToClientDataUdpPtr senddata_udp, LogPtr log, CommandPtr command ) :
_senddata_udp( senddata_udp ),
_command( command ) {
}

ProcessorForServer::~ProcessorForServer( ) {
}

void ProcessorForServer::update( ) {
	_command->update( );
}