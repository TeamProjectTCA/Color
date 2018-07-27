#include "ViewLog.h"
#include "Log.h"
#include "Sheet.h"

const short int COL_PITCH = 500;

ViewLog::ViewLog( LogConstPtr log ) :
_log( log ) {
	_sheet = SheetPtr( new Sheet( _log->getRow( ), false ) );
	_sheet->addCol( COL_PITCH );
}

ViewLog::~ViewLog( ) {
}

void ViewLog::initialize( ) {
	updateSheet( );
}

void ViewLog::updateSheet( ) {
	const int ROW = _log->getRow( );
	for ( int i = 0; i < ROW; i++ ) {
		_sheet->write( 0, i, _log->getLog( i ) );
	}
}

SheetPtr ViewLog::getSheet( ) const {
	return _sheet;
}
