#include "ViewerForServer.h"
#include "ProcessorForServer.h"
#include "Table.h"
#include "Sheet.h"
#include "Drawer.h"

ViewerForServer::ViewerForServer( ProcessorForServerConstPtr processor ) {
	_table = TablePtr( new Table( ) );
}

ViewerForServer::~ViewerForServer( ) {
}

void ViewerForServer::update( ) {
	_table->draw( );

	DrawerPtr drawer = Drawer::getTask( );
	drawer->flip( );
}
