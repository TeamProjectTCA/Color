#include "ProcessorForServer.h"
#include "ServerToClientDataUdp.h"
#include "ClientToServerData.h"
#include "Command.h"
#include "Player.h"
#include "FieldProperty.h"
#include "Turn.h"
#include "PaintTile.h"
#include "Server.h"
#include "Table.h"
#include "Log.h"
#include "NWManagerForServer.h"

ProcessorForServer::ProcessorForServer( ServerToClientDataUdpPtr senddata_udp, NWManagerForServerConstPtr network, LogPtr log, CommandPtr command, TablePtr viewer ) :
_senddata_udp( senddata_udp ),
_command( command ),
_network( network ) {

	for ( int i = 0; i < PLAYER_NUM; i++ ) {
		_player[ i ] = PlayerPtr( new Player( i ) );
	}

	_turn = TurnPtr( new Turn( _player ) );
	_paint = PaintTilePtr( new PaintTile );

	viewer->add( _player[ 0 ]->getSheet( ), Table::NEXT_POS_DOWN );
	viewer->add( _player[ 1 ]->getSheet( ), Table::NEXT_POS_DOWN );
	viewer->add( _turn->getSheet( )       , Table::NEXT_POS_DOWN );
	viewer->add( _paint->getSheet( )      , Table::NEXT_POS_RIGHT );
	viewer->add( log->getSheet( )         , Table::NEXT_POS_DOWN );
	viewer->add( _command->getSheet( )    , Table::NEXT_POS_DOWN );
}

ProcessorForServer::~ProcessorForServer( ) {
}

void ProcessorForServer::update( ) {
	_command->update( );
	_turn->update( );

	// データを詰める
	packageDataUdp( );

	// データを受信
	recv( );
}

void ProcessorForServer::packageDataUdp( ) {
	for ( int i = 0; i < PLAYER_NUM; i++ ) {
		_player[ i ]->package( _senddata_udp );
	}
	_turn->package( _senddata_udp );
	_paint->package( _senddata_udp );
}

void ProcessorForServer::recv( ) {
	if ( !_network->isRecieving( ) ) { 
		return;
	}

	ClientToServerDataConstPtr data = _network->getRecvData( );

	switch ( data->getDataType( ) ) {
	case ClientToServerData::DATA_TYPE_PLAYER:
		recvPlayer( data );
		break;

	default:
		int check = 0;
		break;
	}
}

void ProcessorForServer::recvPlayer( ClientToServerDataConstPtr data ) {
	int player_idx = data->getPlayerIdx( );
	Vector pos = data->getClickMas( );

	_player[ player_idx ]->setPos( pos );
	_paint->setTile( pos, player_idx );
}