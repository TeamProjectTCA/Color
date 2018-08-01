#include "Area.h"

Area::Area( const Vector ORIGIN_POS ) :
_origin( ORIGIN_POS ) {
}

Area::~Area( ) {
}

Vector Area::getOrigin( ) const {
	return _origin;
}
