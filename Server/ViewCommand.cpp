#include "ViewCommand.h"
#include "Command.h"
#include "Sheet.h"

const int TAG_PITCH = 80;
const int VALUE_PITCH = 420;

ViewCommand::ViewCommand( CommandConstPtr command ) :
_command( command ) {
	_sheet = SheetPtr( new Sheet( 1 ) );
	_sheet->addCol( TAG_PITCH );
	_sheet->addCol( VALUE_PITCH );
	_sheet->write( 0, 0, "COMMAND" );

	updateSheet( );
}

ViewCommand::~ViewCommand( ) {
}

void ViewCommand::updateSheet( ) {
	_sheet->write( 1, 0, _command->getInputString( ) );
}

SheetPtr ViewCommand::getSheet( ) const {
	return _sheet;
}