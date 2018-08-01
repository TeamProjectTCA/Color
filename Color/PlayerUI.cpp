#include "PlayerUI.h"

PlayerUI::PlayerUI( const Vector ORIGIN_POS ) :
Area( ORIGIN_POS ) {
}

PlayerUI::~PlayerUI( ) {
}

Vector PlayerUI::getPlayerImagePos( ) const {
	Vector origin = getOrigin( );

	return origin;
}