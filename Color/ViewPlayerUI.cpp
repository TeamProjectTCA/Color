#include "ViewPlayerUI.h"
#include "PlayerUI.h"
#include "Drawer.h"

ViewPlayerUI::ViewPlayerUI( PlayerUIConstPtr player_ui ) :
_player_ui( player_ui ) {
}

ViewPlayerUI::~ViewPlayerUI( ) {
}

void ViewPlayerUI::draw( ) const {
	DrawerPtr drawer = Drawer::getTask( );
	Vector pos = _player_ui->getPlayerImagePos( );

	drawer->drawCircle( ( float )pos.x, ( float )pos.y, 10, 0x00ff00, true );
}
