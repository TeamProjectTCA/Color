#include "PlayerUI.h"
#include "Manager.h"

const Vector DEFAULT_PLAYER_IMAGE = Vector( 150, 150 );

PlayerUI::PlayerUI( const Vector ORIGIN_POS ) :
Area( ORIGIN_POS ),
_full_hd( false ) {
	ManagerPtr manager = Manager::getInstance( );
	if ( manager->getScreenHeight( ) == 1080 ) {
		_full_hd = true;
	}
}

PlayerUI::~PlayerUI( ) {
}

Vector PlayerUI::getPlayerImagePos( ) const {
	Vector origin = getOrigin( );
	Vector pos = DEFAULT_PLAYER_IMAGE;
	if ( _full_hd ) {
		pos *= 1.5;
	}

	return pos + origin;
}