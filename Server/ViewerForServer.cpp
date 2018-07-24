#include "ViewerForServer.h"
#include "ProcessorForServer.h"
#include "Table.h"
#include "Sheet.h"
#include "Drawer.h"
#include "Log.h"

ViewerForServer::ViewerForServer( ProcessorForServerConstPtr processor, LogConstPtr log ) {
	_table = TablePtr( new Table( ) );
	_table->add( log->getSheet( ), Table::NEXT_POS_DOWN );
}

ViewerForServer::~ViewerForServer( ) {
}

void ViewerForServer::update( ) {
	_table->draw( );

	DrawerPtr drawer = Drawer::getTask( );
	drawer->flip( );
}
