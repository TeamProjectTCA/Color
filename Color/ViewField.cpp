#include "ViewField.h"
#include "Field.h"
#include "Drawer.h"
#include "Image.h"

const char TILE_IMAGE[ ] = "Field/WhiteTile.png";

ViewField::ViewField( FieldConstPtr field ) :
_field( field ) {
}

ViewField::~ViewField( ) {
}

void ViewField::draw( ) const {
	DrawerPtr drawer = Drawer::getTask( );
	ImagePtr base_tile = drawer->getImage( TILE_IMAGE );

	for ( int i = 0; i < FieldProperty::FIELD_ROW; i++ ) {
		for ( int j = 0; j < FieldProperty::FIELD_COL; j++ ) {
			ImagePtr tile( new Image( ) );
			tile->setHandle( base_tile->getHandle( ) );
			tile->setCentral( true );

			Vector pos = _field->getTilePos( j, i );
			tile->setPos( ( int )pos.x, ( int )pos.y );
			tile->draw( );
		}
	}
}