#include "Players.h"
#include "Player.h"
#include "Table.h"
#include "ServerToClientDataTcp.h"
#include "Server.h"
#include "Sheet.h"

const int RESPAWN_POSSIBLE_NUM = 4;

const int SHEET_RESPAWN_ROW = 2;
const int SHEET_TAG_PITCH = 200;
const int SHEET_VALUE_PITCH = 100;

Players::Players( BattleFieldConstPtr field, TablePtr viewer ) :
_respawn_count( 0 ) {
	for ( int i = 0; i < PLAYER_NUM; i++ ) {
		_players[ i ] = PlayerPtr( new Player( i, field ) );
	}

	_sheet_respawn = SheetPtr( new Sheet( SHEET_RESPAWN_ROW ) );
	_sheet_respawn->addCol( SHEET_TAG_PITCH );
	_sheet_respawn->addCol( SHEET_VALUE_PITCH );
	_sheet_respawn->write( 0, 0, "RESPAWN POSSIBLE NUM" );
	_sheet_respawn->write( 1, 0, std::to_string( RESPAWN_POSSIBLE_NUM ) );
	_sheet_respawn->write( 0, 1, "RESPAWN COUNT" );

	updateSheet( );

	// table
	viewer->add( _sheet_respawn, Table::NEXT_POS_DOWN );
	for ( PlayerConstPtr player : _players ) {
		viewer->add( player->getSheet( ), Table::NEXT_POS_DOWN );
	}
}

Players::~Players( ) {
}

void Players::update( ) {
	for ( PlayerPtr player : _players ) {
		player->update( );

		if ( player->isRespawn( ) ) {
			_respawn_count++;
			updateSheet( );
		}
	}

	if ( _respawn_count == RESPAWN_POSSIBLE_NUM ) {
		gameset( );
	}
}

void Players::package( ServerToClientDataUdpPtr senddata ) {
	for ( PlayerPtr player : _players ) {
		player->package( senddata );
	}
}

void Players::gameset( ) {
	ServerToClientDataTcpPtr senddata( new ServerToClientDataTcp );
	senddata->setGameOver( true );

	ServerPtr server = Server::getTask( );
	server->sendTcp( senddata );
}

void Players::updateSheet( ) {
	_sheet_respawn->write( 1, 1, std::to_string( _respawn_count ) );
}

int Players::getPlayerNum( ) const {
	return PLAYER_NUM;
}

PlayerConstPtr Players::getPlayer( int player_idx ) const {
	return _players[ player_idx ];
}