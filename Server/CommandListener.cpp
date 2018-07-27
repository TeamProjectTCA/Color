#include "CommandListener.h"

CommandListener::CommandListener( ) {
}

CommandListener::~CommandListener( ) {
}

void CommandListener::addErrorLog( std::string error ) {
	_error = error;
}

std::string CommandListener::getErrorLog( ) const {
	return _error;
}