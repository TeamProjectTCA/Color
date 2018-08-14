#include "Turn.h"
#include "Player.h"
#include "Server.h"
#include "ServerToClientDataTcp.h"

Turn::Turn( const std::array< PlayerPtr, 2 > &player ) :
_turn( TURN_MAX ),
_active_player( 0 ) {
	_player[ 0 ] = player[ 0 ];
	_player[ 1 ] = player[ 1 ];

	std::array< Vector, 2 >( ).swap( _past_pos );
}

Turn::~Turn( ) {
}

void Turn::update( ) {
	for ( int i = 0; i < 2; i++ ) {
		Vector pos = _player[ i ]->getPos( );
		if ( pos == _past_pos[ i ] ) {
			continue;
		}

		_past_pos[ i ] = pos;

		_active_player++;
		// プレイヤー全てが更新したらターンを減らす
		if ( _active_player == _player.size( ) - 1 ) {
			_active_player = 0;
			countTurn( );
		}
	}

	if ( _turn == 0 ) {
		ServerToClientDataTcpPtr senddata( new ServerToClientDataTcp );
		senddata->setGameOver( true );

		ServerPtr server = Server::getTask( );
		server->sendTcp( senddata );
	}
}

int Turn::getTurn( ) const {
	return _turn;
}

int Turn::getActivePlayer( ) const {
	return _active_player;
}

void Turn::countTurn( ) {
	_turn--;
}