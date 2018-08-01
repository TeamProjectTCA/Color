#include "ViewChara.h"
#include "Chara.h"
#include "Drawer.h"

ViewChara::ViewChara( CharaConstPtr player ) :
_player( player ) {
}

ViewChara::~ViewChara( ) {
}

void ViewChara::draw( ) const {
	DrawerPtr drawer = Drawer::getTask( );
	Vector pos = _player->getPos( );

	drawer->drawCircle( ( float )pos.x, ( float )pos.y, 10, 0xff0000, true );
}
