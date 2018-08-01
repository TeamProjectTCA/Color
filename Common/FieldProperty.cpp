#include "FieldProperty.h"

FieldProperty::FieldProperty( ) {
}

FieldProperty::~FieldProperty( ) {
}

Vector FieldProperty::getPlayer0InitPos( ) const {
	Vector pos = Vector( 0, FIELD_ROW - 1 );
	return pos;
}

Vector FieldProperty::getPlayer1InitPos( ) const {
	Vector pos = Vector( FIELD_COL - 1, 0 );
	return pos;
}