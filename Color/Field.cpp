#include "Field.h"

Field::Field( const Vector ORIGIN_POS ) :
Area( ORIGIN_POS ){
}

Field::~Field( ) {
}

Vector Field::getCenterPos( ) const {
	Vector origin = getOrigin( );

	return origin;
}