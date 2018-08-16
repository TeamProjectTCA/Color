#include "Chara.h"
#include "Field.h"
#include "Drawer.h"

Chara::Chara( FieldConstPtr field ) :
_field( field ),
_pos( Vector( ) ) {
}

Chara::~Chara( ) {
}

void Chara::update( ) {
}

void Chara::draw( ) const {
	DrawerPtr drawer = Drawer::getTask( );
	Vector pos = getScreenPos( );

	drawer->drawCircle( ( float ) pos.x, ( float ) pos.y, 10, 0x000000, true );
}

void Chara::setFieldIdx( Vector pos ) {
	_pos = pos;
}

Vector Chara::getFieldIdx( ) const {
	return _pos;
}

Vector Chara::getScreenPos( ) const {
	Vector result = _field->getTilePos( ( int )_pos.x, ( int )_pos.y );
	return result;
}
