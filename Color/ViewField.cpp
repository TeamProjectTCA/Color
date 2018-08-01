#include "ViewField.h"
#include "Field.h"
#include "Drawer.h"

ViewField::ViewField( FieldConstPtr field ) :
_field( field ) {
}

ViewField::~ViewField( ) {
}

void ViewField::draw( ) const {
	DrawerPtr drawer = Drawer::getTask( );
	Vector pos = _field->getCenterPos( );
	drawer->drawCircle( ( float )pos.x, ( float )pos.y, 30, 0xff0000, true );
}