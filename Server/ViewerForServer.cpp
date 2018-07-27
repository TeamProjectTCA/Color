#include "ViewerForServer.h"
#include "ProcessorForServer.h"
#include "NWManagerForServer.h"
#include "Table.h"
#include "Sheet.h"
#include "Drawer.h"
#include "Log.h"
#include "ViewConnectorForServer.h"
#include "ViewCommand.h"
#include "ViewLog.h"

ViewerForServer::ViewerForServer( ProcessorForServerConstPtr processor, NWManagerForServerConstPtr network_manager, LogConstPtr log, CommandConstPtr command ) {
	_connector = ViewConnectorForServerPtr( new ViewConnectorForServer( network_manager->getConnectorPtr( ) ) );
	_command = ViewCommandPtr( new ViewCommand( command ) );
	_log = ViewLogPtr( new ViewLog( log ) );

	_table = TablePtr( new Table( ) );
	_table->add( _connector->getSheet( )     , Table::NEXT_POS_RIGHT );
	_table->add( _log->getSheet( )            , Table::NEXT_POS_DOWN );
	_table->add( _command->getSheet( )       , Table::NEXT_POS_DOWN );
}

ViewerForServer::~ViewerForServer( ) {
}

void ViewerForServer::initialize( ) {
	_connector->initialize( );
	_command->initialize( );
	_log->initialize( );
	
	_table->draw( );

	DrawerPtr drawer = Drawer::getTask( );
	drawer->flip( );
}

void ViewerForServer::update( ) {
	_connector->updateSheet( );
	_command->updateSheet( );
	_log->updateSheet( );

	_table->draw( );

	DrawerPtr drawer = Drawer::getTask( );
	drawer->flip( );
}
