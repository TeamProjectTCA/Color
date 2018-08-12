#include "ProcessorForServer.h"
#include "ServerToClientDataUdp.h"
#include "ServerToClientDataTcp.h"
#include "ClientToServerData.h"
#include "Command.h"
#include "Player.h"
#include "FieldProperty.h"
#include "Turn.h"

ProcessorForServer::ProcessorForServer( ClientToServerDataConstPtr recv_data, ServerToClientDataUdpPtr senddata_udp, LogPtr log, CommandPtr command ) :
_recv_data( recv_data ),
_senddata_udp( senddata_udp ),
_command( command ) {
	FieldPropertyPtr field_property( new FieldProperty );
	
	_player_init_pos[ 0 ] = field_property->getPlayer0InitPos( );
	_player_init_pos[ 1 ] = field_property->getPlayer1InitPos( );

	_player[ 0 ] = PlayerPtr( new Player( 0, _player_init_pos[ 0 ] ) );
	_player[ 1 ] = PlayerPtr( new Player( 1, _player_init_pos[ 1 ] ) );

	_turn = TurnPtr( new Turn );
}

ProcessorForServer::~ProcessorForServer( ) {
}

void ProcessorForServer::update( ) {
	_command->update( );

	packageData( );
	playerMove( );
}

void ProcessorForServer::packageData( ) {
	_senddata_udp->setPlayerPos( 0, _player[ 0 ]->getPos( ) );
	_senddata_udp->setPlayerPos( 1, _player[ 1 ]->getPos( ) );
	_senddata_udp->setTurn( _turn->getTurn( ) );
}

void ProcessorForServer::playerMove( ) {

	Vector click_mas = _recv_data->getClickMas( );
	int player_num = _recv_data->getPlayerNum( );

	if ( click_mas == Vector( ) ) {
		return;
	}

	if ( ( player_num == _turn->getTurn( ) % 2 ) &&
		 ( click_mas != _player_init_pos[ ( _turn->getTurn( ) + 1 ) % 2 ] + Vector( 1, 1 ) ) ) {
		_player[ player_num ]->setPos( click_mas - Vector( 1, 1 ) );
		_turn->countTurn( );
	}
}

void ProcessorForServer::sendGameOver( ) {
	if ( _turn == 0 ) {
		ServerToClientDataTcpPtr senddata_tcp( new ServerToClientDataTcp );
		senddata_tcp->setGameOver( true );
	}
}

int ProcessorForServer::getTurn( ) const {
	return _turn->getTurn( );
}
const int ProcessorForServer::getTURNMAX( ) const {
	return _turn->getTURNMAX( );
}

PlayerConstPtr ProcessorForServer::getPlayer0Ptr( ) const {
	return _player[ 0 ];
}

PlayerConstPtr ProcessorForServer::getPlayer1Ptr( ) const {
	return _player[ 1 ];
}