#include "ProcessorForServer.h"
#include "ServerToClientDataUdp.h"
#include "Command.h"
#include "Player.h"
#include "FieldProperty.h"

ProcessorForServer::ProcessorForServer( ServerToClientDataUdpPtr senddata_udp, LogPtr log, CommandPtr command ) :
_senddata_udp( senddata_udp ),
_command( command ) {
	FieldPropertyPtr field_property( new FieldProperty );
	_player0 = PlayerPtr( new Player( 0, field_property->getPlayer0InitPos( ) ) );
	_player1 = PlayerPtr( new Player( 1, field_property->getPlayer1InitPos( ) ) );
}

ProcessorForServer::~ProcessorForServer( ) {
}

void ProcessorForServer::update( ) {
	_command->update( );

	packageData( );
}

void ProcessorForServer::packageData( ) {
	_senddata_udp->setPlayer0Pos( _player0->getPos( ) );
	_senddata_udp->setPlayer1Pos( _player1->getPos( ) );
}

PlayerConstPtr ProcessorForServer::getPlayer0Ptr( ) const {
	return _player0;
}

PlayerConstPtr ProcessorForServer::getPlayer1Ptr( ) const {
	return _player1;
}