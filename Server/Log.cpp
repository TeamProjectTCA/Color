#include "Log.h"

Log::Log( ) {
}

Log::~Log( ) {
}

void Log::add( std::string log ) {
	for ( int i = 0; i < ROW; i++ ) {
		if ( i == 0 ) {
			continue;
		}

		std::string value = _log[ i ];
		_log[ i - 1 ] = value;
	}

	_log[ ROW - 1 ] = log;
}

int Log::getRow( ) const {
	return ROW;
}

std::string Log::getLog( int idx ) const {
	std::string log;
	if ( idx >= ROW ) {
		log = "";
	} else {
		log = _log[ idx ];
	}

	return log;
}