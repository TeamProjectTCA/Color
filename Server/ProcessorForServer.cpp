#include "ProcessorForServer.h"
#include "ServerToClientDataUdp.h"

ProcessorForServer::ProcessorForServer( ServerToClientDataUdpPtr senddata_udp ) :
_senddata_udp( senddata_udp ) {
}

ProcessorForServer::~ProcessorForServer( ) {
}
