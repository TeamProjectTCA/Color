#include "Move.h"
#include "Mouse.h"
#include "Chara.h"
#include "Field.h"
#include "FieldProperty.h"
#include "User.h"
#include "Client.h"
#include "ClientToServerData.h"

Move::Move( FieldConstPtr field, UserConstPtr user ) :
_user( user ),
_TILE_SIZE( field->getTileSize( ) ),
_START_POS( field->getTilePos( 0, 0 ) - Vector( _TILE_SIZE / 2, _TILE_SIZE / 2 ) ) {
}

Move::~Move( ) {
}

void Move::update( ) {
	MousePtr mouse = Mouse::getTask( );
	if ( !mouse->isClickDownLeft( ) ) {
		return;
	}

	Vector mouse_screen_pos = mouse->getPoint( ) - _START_POS;
	Vector mouse_idx = Vector( );
	mouse_idx.x = ( int )( mouse_screen_pos.x / _TILE_SIZE );
	mouse_idx.y = ( int )( mouse_screen_pos.y / _TILE_SIZE );

	Vector chara_idx = _user->getFieldIdx( );

	if ( 0 > mouse_idx.x || 0 > mouse_idx.y ) {
		return;
	}
	if ( mouse_idx.x >= FieldProperty::FIELD_COL || mouse_idx.y >= FieldProperty::FIELD_ROW ) {
		return;
	}

	Vector delta = mouse_idx - chara_idx;

	if ( ( abs( delta.x ) + abs( delta.y ) == 1 ) || ( abs( delta.x ) * abs( delta.y ) == 1 ) ) {
		ClientToServerDataPtr send_data = ClientToServerDataPtr( new ClientToServerData );
		send_data->setClickMas( mouse_idx );
		send_data->setPlayerNum( _user->getPlayerNum( ) );

		ClientPtr client = Client::getTask( );
		client->sendTcp( send_data );
	}
}
