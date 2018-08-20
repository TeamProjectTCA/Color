#include "ViewerForServer.h"
#include "Table.h"
#include "Drawer.h"

ViewerForServer::ViewerForServer( TableConstPtr table ) :
_table( table ) {
}

ViewerForServer::~ViewerForServer( ) {
}

void ViewerForServer::update( ) {
	_table->draw( );

	DrawerPtr drawer = Drawer::getTask( );
	drawer->flip( );
}