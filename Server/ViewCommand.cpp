#include "ViewCommand.h"
#include "Command.h"
#include "Sheet.h"

const int TAG_PITCH = 100;
const int VALUE_PITCH = 200;

ViewCommand::ViewCommand( CommandConstPtr command ) :
_command( command ) {
	_sheet = SheetPtr( new Sheet( 1 ) );
	_sheet->addCol( TAG_PITCH );
	_sheet->addCol( VALUE_PITCH );
	_sheet->write( 0, 0, "COMMAND" );
}

ViewCommand::~ViewCommand( ) {
}

void ViewCommand::updataSheet( ) {
	_sheet->write( 1, 0, _command->getInputString( ) );
}

SheetPtr ViewCommand::getSheet( ) const {
	return _sheet;
}