#include "Turn.h"
#include "Player.h"
#include "Server.h"
#include "ServerToClientDataTcp.h"
#include "ServerToClientDataUdp.h"
#include "Sheet.h"

const int SHEET_ROW = 2;
const int SHEET_TAG_PITCH = 150;
const int SHEET_VALUE_PITCH = 150;

Turn::Turn( const std::array< PlayerPtr, PLAYER_NUM > &player ) :
_turn( TURN_MAX ),
_active_player( 0 ) {
	_player[ 0 ] = player[ 0 ];
	_player[ 1 ] = player[ 1 ];

	for ( int i = 0; i < PLAYER_NUM; i++ ) {
		_past_pos[ i ] = _player[ i ]->getPos( );
	}

	_sheet = SheetPtr( new Sheet( SHEET_ROW ) );
	_sheet->addCol( SHEET_TAG_PITCH );
	_sheet->addCol( SHEET_VALUE_PITCH );
	_sheet->write( 0, 0, "Turn" );
	_sheet->write( 0, 1, "TurnMax" );

	updateSheet( );
}

Turn::~Turn( ) {
}

void Turn::update( ) {
	for ( int i = 0; i < PLAYER_NUM; i++ ) {
		Vector pos = _player[ i ]->getPos( );
		if ( pos == _past_pos[ i ] ) {
			continue;
		}

		_past_pos[ i ] = pos;

		_active_player++;
		// プレイヤー全てが更新したらターンを減らす
		if ( _active_player == _player.size( ) ) {
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

void Turn::updateSheet( ) {
	_sheet->write( 1, 0, std::to_string( _turn ) );
	_sheet->write( 1, 1, std::to_string( TURN_MAX ) );
}

int Turn::getActivePlayer( ) const {
	return _active_player;
}

void Turn::countTurn( ) {
	_turn--;
	updateSheet( );
}

void Turn::package( ServerToClientDataUdpPtr senddata ) {
	senddata->setTurn( _turn );
}

SheetPtr Turn::getSheet( ) const {
	return _sheet;
}