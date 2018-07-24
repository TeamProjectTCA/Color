#include "NWManagerForServer.h"
#include "ClientToServerData.h"
#include "ServerToClientDataUdp.h"
#include "ProcessorForServer.h"
#include "ConnectorForServer.h"

NWManagerForServer::NWManagerForServer( ClientToServerDataConstPtr recvdata, ServerToClientDataUdpPtr senddata_udp, ProcessorForServerPtr processor, LogPtr log ) :
_recvdata( recvdata ),
_senddata_udp( senddata_udp ),
_processor( processor ) {
	_connector = ConnectorForServerPtr( new ConnectorForServer( log ) );
}

NWManagerForServer::~NWManagerForServer( ) {
}

void NWManagerForServer::update( ) {
	_connector->update( );
}