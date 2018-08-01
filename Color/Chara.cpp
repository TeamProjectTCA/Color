#include "Chara.h"
#include "Field.h"

Chara::Chara( FieldConstPtr field ) :
_field( field ) {
	_pos = _field->getTilePos( 0, 0 );
}

Chara::~Chara( ) {
}

void Chara::setPos( Vector pos ) {
	_pos = pos;
}

Vector Chara::getPos( ) const {
	return _pos;
}
