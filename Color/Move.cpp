#include "Move.h"
#include "Mouse.h"
#include "Chara.h"
#include "Field.h"
#include "FieldProperty.h"
#include "User.h"
#include "Client.h"
#include "ClientToServerData.h"

Move::Move( FieldConstPtr field, UserPtr user ) :
_field( field ),
_user( user ) {
}

Move::~Move( ) {
}

void Move::update( ) {
	sendClickMas( );
}

void Move::sendClickMas( ) {
	const int TILE_SIZE = _field->getTileSize( );
	const Vector START_POS = Vector( _field->getTilePos( 0, 0 ) - Vector( TILE_SIZE / 2, TILE_SIZE / 2 ) );

	MousePtr mouse = Mouse::getTask( );
	Vector pos = mouse->getPoint( );
	pos -= START_POS;
	Vector mas_idx = Vector( ( int ) pos.x / TILE_SIZE, ( int ) pos.y / TILE_SIZE );

	Vector chara_pos = _user->getPos( );
	chara_pos -= START_POS;
	Vector chara_idx = Vector( ( int ) chara_pos.x / TILE_SIZE, ( int ) chara_pos.y / TILE_SIZE );


	if ( 0 <= pos.x && pos.x <= TILE_SIZE * FieldProperty::FIELD_COL &&
		 0 <= pos.y && pos.y <= TILE_SIZE * FieldProperty::FIELD_ROW ) {
		if ( mouse->isClickDownLeft( ) ) {
			Vector delta = mas_idx - chara_idx;
			if ( ( abs( delta.x ) + abs( delta.y ) == 1 ) || ( abs( delta.x ) * abs( delta.y ) == 1 ) ) {
				ClientPtr client = Client::getTask( );
				ClientToServerDataPtr send_data = ClientToServerDataPtr( new ClientToServerData );
				send_data->setClickMas( mas_idx + Vector( 1, 1 ) );
				send_data->setPlayerNum( _user->getPlayerNum( ) );
				client->sendTcp( send_data );
			}
		}
	}
}