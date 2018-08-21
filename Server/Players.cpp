#include "Players.h"
#include "Player.h"
#include "Table.h"

Players::Players( BattleFieldConstPtr field, TablePtr viewer ) :
_respawn_count( 0 ) {
	for ( int i = 0; i < PLAYER_NUM; i++ ) {
		_players[ i ] = PlayerPtr( new Player( i, field ) );
	}

	// table
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
		}
	}
}

void Players::package( ServerToClientDataUdpPtr senddata ) {
	for ( PlayerPtr player : _players ) {
		player->package( senddata );
	}
}

int Players::getPlayerNum( ) const {
	return PLAYER_NUM;
}

PlayerConstPtr Players::getPlayer( int player_idx ) const {
	return _players[ player_idx ];
}