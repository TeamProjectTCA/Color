#include "Move.h"
#include "Mouse.h"
#include "Chara.h"
#include "Field.h"
#include "FieldProperty.h"


Move::Move( FieldConstPtr field ) :
_field( field ) {
}

Move::~Move( ) {
}

Vector Move::getClickMas( ) const {
	const int TILE_SIZE = _field->getTileSize( );
	const Vector START_POS = Vector( _field->getTilePos( 0, 0 ) - Vector( TILE_SIZE / 2, TILE_SIZE / 2 ) );
	
	MousePtr mouse = Mouse::getTask( );
	Vector pos = mouse->getPoint( );
	pos -= START_POS;
	Vector mas_idx = Vector( ( int ) pos.x / TILE_SIZE, ( int ) pos.y / TILE_SIZE );

	if ( 0 <= pos.x && pos.x <= TILE_SIZE * FieldProperty::FIELD_COL &&
	 	 0 <= pos.y && pos.y <= TILE_SIZE * FieldProperty::FIELD_ROW ) {
		if ( mouse->isClickDownLeft( ) ) {
				return mas_idx + Vector( 1, 1 );
		}
	}
	return Vector( );
}