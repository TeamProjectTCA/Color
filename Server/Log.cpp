#include "Log.h"
#include "Sheet.h"

const short int ROW_NUM = 18;
const short int COL_PITCH = 400;

Log::Log( ) {
	_sheet = SheetPtr( new Sheet( ROW_NUM, false ) );
	_sheet->addCol( COL_PITCH );
}

Log::~Log( ) {
}

void Log::add( std::string log ) {
	for ( int i = 0; i < ROW_NUM; i++ ) {
		if ( i == 0 ) {
			continue;
		}

		std::string value = _sheet->getValue( 0, i );
		_sheet->write( 0, i - 1, value );
	}

	_sheet->write( 0, ROW_NUM - 1, log );
}

SheetPtr Log::getSheet( ) const {
	return _sheet;
}