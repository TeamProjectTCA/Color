#include "ViewTurn.h"
#include "ProcessorForServer.h"
#include "Sheet.h"

const int SHEET_ROW = 2;
const int SHEET_TAG_PITCH = 150;
const int SHEET_VALUE_PITCH = 150;

ViewTurn::ViewTurn( ProcessorForServerConstPtr processor ) :
_processor( processor ) {
	_sheet = SheetPtr( new Sheet( SHEET_ROW ) );
	_sheet->addCol( SHEET_TAG_PITCH );
	_sheet->addCol( SHEET_VALUE_PITCH );
	_sheet->write( 0, 0, "Turn" );
	_sheet->write( 0, 1, "TurnMax" );
}

ViewTurn::~ViewTurn( ) {
}

void ViewTurn::initialize( ) {
	updateSheet( );
}

void ViewTurn::updateSheet( ) {

	_sheet->write( 1, 0, std::to_string( ( _processor->getTurn( ) + 1 ) / 2 ) );
	_sheet->write( 1, 1, std::to_string( _processor->getTURNMAX( ) / 2 ) );
}

SheetPtr ViewTurn::getSheet( ) const {
	return _sheet;
}