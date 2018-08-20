#include "Log.h"
#include "Sheet.h"

const short int COL_PITCH = 500;

Log::Log( ) {
	_sheet = SheetPtr( new Sheet( ROW, false ) );
	_sheet->addCol( COL_PITCH );

	updateSheet( );
}

Log::~Log( ) {
}

void Log::updateSheet( ) {
	for ( int i = 0; i < ROW; i++ ) {
		_sheet->write( 0, i, _log[ i ] );
	}
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

	updateSheet( );
}

int Log::getRow( ) const {
	return ROW;
}

SheetPtr Log::getSheet( ) const {
	return _sheet;
}
