#pragma once
#include "smart_ptr.h"

PTR( ViewerForServer );
PTR( ProcessorForServer );
PTR( NWManagerForServer );
PTR( Table );
PTR( Log );
PTR( Command );
PTR( ViewConnectorForServer );
PTR( ViewCommand );
PTR( ViewLog );
PTR( ViewPlayer );
PTR( ViewTurn );

class ViewerForServer {
public:
	ViewerForServer( ProcessorForServerConstPtr processor, NWManagerForServerConstPtr network_manager, LogConstPtr log, CommandConstPtr command );
	virtual ~ViewerForServer( );

public:
	void initialize( );
	void update( );

private:
	TablePtr _table;
	ViewConnectorForServerPtr _connector;
	ViewCommandPtr _command;
	ViewLogPtr _log;
	ViewPlayerPtr _player0;
	ViewPlayerPtr _player1;
	ViewTurnPtr _turn;
};

