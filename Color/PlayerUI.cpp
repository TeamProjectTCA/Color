#include "PlayerUI.h"
#include "Manager.h"
#include "Drawer.h"

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

void PlayerUI::draw( ) const {
	DrawerPtr drawer = Drawer::getTask( );
	Vector pos = getPlayerImagePos( );

	drawer->drawCircle( ( float ) pos.x, ( float ) pos.y, 10, 0x00ff00, true );
}

Vector PlayerUI::getPlayerImagePos( ) const {
	Vector origin = getOrigin( );
	Vector pos = DEFAULT_PLAYER_IMAGE;
	if ( _full_hd ) {
		pos *= 1.5;
	}

	return pos + origin;
}