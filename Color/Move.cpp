#include "Move.h"
#include "Mouse.h"
#include "Chara.h"
#include "Field.h"
#include "FieldProperty.h"
#include "User.h"
#include <cmath>


Move::Move( FieldConstPtr field, CharaPtr user ):
_field( field ),
_user( user ) {
}

Move::~Move( ) {
}

Vector Move::getClickMas( ) const {
	const int TILE_SIZE = _field->getTileSize( );
	const Vector START_POS = Vector( _field->getTilePos( 0, 0 ) - Vector( TILE_SIZE / 2, TILE_SIZE / 2 ) );
	//マウス座標
	MousePtr mouse = Mouse::getTask( );
	Vector pos = mouse->getPoint( );
	pos -= START_POS;
	Vector mas_idx = Vector( ( int ) pos.x / TILE_SIZE, ( int ) pos.y / TILE_SIZE );

	//キャラ座標
	Vector chara_pos = _user->getPos( );
	chara_pos -= START_POS;
	Vector chara_idx = Vector( ( int ) chara_pos.x / TILE_SIZE, ( int ) chara_pos.y / TILE_SIZE );

	if ( 0 <= pos.x && pos.x <= TILE_SIZE * FieldProperty::FIELD_COL &&
	 	 0 <= pos.y && pos.y <= TILE_SIZE * FieldProperty::FIELD_ROW ) {
		if ( mouse->isClickDownLeft( ) ) {
			Vector check = chara_idx - mas_idx;
			if ( ( abs( ( int ) check.x ) == 1 && abs( ( int ) check.y ) == 0 ) ||
				 ( abs( ( int ) check.x ) == 0 && abs( ( int ) check.y ) == 1 ) || 
				 ( abs( ( int ) check.x ) == 1 && abs( ( int ) check.y ) == 1 ) ) {
				return mas_idx + Vector( 1, 1 );
			}
		}
	}
	return Vector( );
}