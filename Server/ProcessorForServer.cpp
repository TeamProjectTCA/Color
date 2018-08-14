#include "ProcessorForServer.h"
#include "ServerToClientDataUdp.h"
#include "ServerToClientDataTcp.h"
#include "ClientToServerData.h"
#include "Command.h"
#include "Player.h"
#include "FieldProperty.h"
#include "Turn.h"
#include "Server.h"

ProcessorForServer::ProcessorForServer( ServerToClientDataUdpPtr senddata_udp, LogPtr log, CommandPtr command ) :
_senddata_udp( senddata_udp ),
_command( command ) {
	FieldPropertyPtr field_property( new FieldProperty );
	
	_player[ 0 ] = PlayerPtr( new Player( 0, field_property->getPlayer0InitPos( ) ) );
	_player[ 1 ] = PlayerPtr( new Player( 1, field_property->getPlayer1InitPos( ) ) );

	_turn = TurnPtr( new Turn( _player ) );
}

ProcessorForServer::~ProcessorForServer( ) {
}

void ProcessorForServer::update( ) {
	_command->update( );
	_turn->update( );

	// ƒf[ƒ^‚ð‹l‚ß‚é
	packageDataUdp( );
}

void ProcessorForServer::packageDataUdp( ) {
	_senddata_udp->setPlayerPos( 0, _player[ 0 ]->getPos( ) );
	_senddata_udp->setPlayerPos( 1, _player[ 1 ]->getPos( ) );
	_senddata_udp->setTurn( _turn->getTurn( ) );
}

void ProcessorForServer::setPlayerPos( int player_num, Vector pos ) {
	_player[ player_num ]->setPos( pos );
}

PlayerConstPtr ProcessorForServer::getPlayer0Ptr( ) const {
	return _player[ 0 ];
}

PlayerConstPtr ProcessorForServer::getPlayer1Ptr( ) const {
	return _player[ 1 ];
}

TurnConstPtr ProcessorForServer::getTurnPtr( ) const {
	return _turn;
}