#include "Chara.h"
#include "Field.h"

Chara::Chara( FieldConstPtr field ) :
_field( field ),
_pos( Vector( ) ) {
}

Chara::~Chara( ) {
}

void Chara::update( ) {
}

void Chara::setPos( Vector pos ) {
	_pos = pos;
}

Vector Chara::getPos( ) const {
	Vector result = _field->getTilePos( ( int )_pos.x, ( int )_pos.y );
	return result;
}
