#include "FieldProperty.h"

FieldProperty::FieldProperty( ) {
}

FieldProperty::~FieldProperty( ) {
}

Vector FieldProperty::getPlayerInitPos( int player_idx ) {
	Vector pos = Vector( );
	
	if ( player_idx == 0 ) {
		pos = Vector( 0, FIELD_ROW - 1 );
	}
	if ( player_idx == 1 ) {
		pos = Vector( FIELD_COL - 1, 0 );
	}

	return pos;
}