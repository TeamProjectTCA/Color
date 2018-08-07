#include "Move.h"
#include "Mouse.h"
#include "Chara.h"
#include "Field.h"
#include "FieldProperty.h"
#include <cmath>

Move::Move( FieldConstPtr field, CharaPtr chara ):
_field( field ),
_chara( chara ),
TILE_SIZE( _field->getTileSize( ) ),
START_POS( _field->getTilePos( 0, 0 ) - Vector( TILE_SIZE / 2, TILE_SIZE / 2 ) ) {
}

Move::~Move( ) {
}

Vector Move::getClickMas( ) {
	//マウス座標
	MousePtr mouse = Mouse::getTask( );
	Vector pos = mouse->getPoint( );
	pos -= START_POS;
	Vector mas_idx = Vector( -2, -2 );
	
	//キャラ座標
	Vector chara_pos = _chara->getPos( );
	chara_pos -= START_POS;
	Vector chara_idx = Vector( chara_pos.x / TILE_SIZE, chara_pos.y / TILE_SIZE );

	Vector check = chara_idx - getClickMas( );

	if ( 0 <= pos.x && pos.x <= TILE_SIZE * FieldProperty::FIELD_COL &&
	 	 0 <= pos.y && pos.y <= TILE_SIZE * FieldProperty::FIELD_ROW ) {
		if ( mouse->isClickDownLeft( ) ) {
			if ( abs( ( int ) check.x ) == 1 || abs( ( int ) check.y ) == 1 ) {
				mas_idx = Vector( pos.x / TILE_SIZE, pos.y / TILE_SIZE );
			}
		}
	}
	return mas_idx;
}