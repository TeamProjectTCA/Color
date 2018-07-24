#include "ProcessorForServer.h"
#include "ServerToClientDataUdp.h"

ProcessorForServer::ProcessorForServer( ServerToClientDataUdpPtr senddata_udp, LogPtr log ) :
_senddata_udp( senddata_udp ) {
}

ProcessorForServer::~ProcessorForServer( ) {
}
