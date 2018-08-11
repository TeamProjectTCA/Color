#include "ProcessorForServer.h"
#include "ServerToClientDataUdp.h"
#include "ServerToClientDataTcp.h"
#include "ClientToServerData.h"
#include "Command.h"
#include "Player.h"
#include "FieldProperty.h"
#include <cmath>

const int TURN_MAX = 40 * 2;

ProcessorForServer::ProcessorForServer( ClientToServerDataConstPtr recv_data, ServerToClientDataUdpPtr senddata_udp, ServerToClientDataTcpPtr senddata_tcp, LogPtr log, CommandPtr command ) :
_recv_data( recv_data ),
_senddata_udp( senddata_udp ),
_senddata_tcp( senddata_tcp ),
_command( command ),
_turn( TURN_MAX ),
sended_tcp( false ) {
	FieldPropertyPtr field_property( new FieldProperty );
	
	_player_init_pos[ 0 ] = field_property->getPlayer0InitPos( );
	_player_init_pos[ 1 ] = field_property->getPlayer1InitPos( );

	_player[ 0 ] = PlayerPtr( new Player( 0, _player_init_pos[ 0 ] ) );
	_player[ 1 ] = PlayerPtr( new Player( 1, _player_init_pos[ 1 ] ) );
}

ProcessorForServer::~ProcessorForServer( ) {
}

void ProcessorForServer::update( ) {
	_command->update( );
	if ( isGameOver( ) ) {
		if ( sended_tcp ) {
			return;
		}
		_senddata_tcp->setGameOver( isGameOver( ) );
		sended_tcp = true;
		return;
	}
	packageData( );
	playerMove( );
}

void ProcessorForServer::packageData( ) {
	_senddata_udp->setPlayerPos( 0, _player[ 0 ]->getPos( ) );
	_senddata_udp->setPlayerPos( 1, _player[ 1 ]->getPos( ) );
	_senddata_udp->setTurn( _turn );
}

void ProcessorForServer::playerMove( ) {
	Vector click_mas = _recv_data->getClickMas( );
	if ( click_mas == Vector( ) ) {
		return;
	}

	Vector chara_idx = _player[ _turn % 2 ]->getPos( );
	Vector delta = click_mas - chara_idx - Vector( 1, 1 );
	if ( ( abs( delta.x ) + abs( delta.y ) == 1 ) || ( abs( delta.x ) * abs( delta.y ) == 1 ) ) {
		if ( click_mas != _player_init_pos[ ( _turn + 1 ) % 2 ] + Vector( 1, 1 ) ) {
			_player[ _turn % 2 ]->setPos( click_mas - Vector( 1, 1 ) );
			_turn--;
		}
	}
}

int ProcessorForServer::getTurn( ) const {
	return _turn;
}
const int ProcessorForServer::getTURNMAX( ) const {
	return TURN_MAX;
}

bool ProcessorForServer::isGameOver( ) const {
	if ( _turn == 0 ) {
		return true;
	}
	return false;
}

PlayerConstPtr ProcessorForServer::getPlayer0Ptr( ) const {
	return _player[ 0 ];
}

PlayerConstPtr ProcessorForServer::getPlayer1Ptr( ) const {
	return _player[ 1 ];
}