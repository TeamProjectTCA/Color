#include "NWManagerForServer.h"
#include "ClientToServerData.h"
#include "ServerToClientDataUdp.h"
#include "ProcessorForServer.h"

NWManagerForServer::NWManagerForServer( ClientToServerDataConstPtr recvdata, ServerToClientDataUdpPtr senddata_udp, ProcessorForServerPtr processor ) :
_recvdata( recvdata ),
_senddata_udp( senddata_udp ),
_processor( processor ) {
}

NWManagerForServer::~NWManagerForServer( ) {
}
