#include "Turn.h"
#include "Player.h"
#include "Server.h"
#include "ServerToClientDataTcp.h"
#include "ServerToClientDataUdp.h"
#include "Sheet.h"
#include "Players.h"

const int SHEET_ROW = 2;
const int SHEET_TAG_PITCH = 150;
const int SHEET_VALUE_PITCH = 150;

Turn::Turn( PlayersConstPtr players ) :
_turn( TURN_MAX ),
_players( players ),
_PLAYER_NUM( _players->getPlayerNum( ) ) {
	_move.reserve( _PLAYER_NUM );
	for ( int i = 0; i < _PLAYER_NUM; i++ ) {
		_move.push_back( false );
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
	for ( int i = 0; i < _PLAYER_NUM; i++ ) {
		PlayerConstPtr player = _players->getPlayer( i );
		if ( player->isMove( ) ) {
			_move[ i ] = true;	
		}
	}

	// ‘Sˆõ“®‚¢‚½‚©‚Ç‚¤‚©
	for ( int i = 0; i < _PLAYER_NUM; i++ ) {
		if ( !_move[ i ] ) {
			return;
		}
	}

	countTurn( );

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

void Turn::countTurn( ) {
	_turn--;

	for ( int i = 0; i < _PLAYER_NUM; i++ ) {
		_move[ i ] = false;
	}

	updateSheet( );
}

void Turn::package( ServerToClientDataUdpPtr senddata ) {
	senddata->setTurn( _turn );
}

SheetPtr Turn::getSheet( ) const {
	return _sheet;
}