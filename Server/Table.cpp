#include "Table.h"
#include "Sheet.h"

const float DEFAULT_X = 20.0f;
const float DEFAULT_Y = 20.0f;
const float SHEET_PITCH = 35.0f;

Table::Table( ) :
_x( DEFAULT_X ),
_y( DEFAULT_Y ) {
}

Table::~Table( ) {
}

void Table::draw( ) const {
	for ( SheetPtr sheet : _sheets ) {
		sheet->draw( );
	}
}

void Table::add( SheetPtr sheet, NEXT_POS next ) {
	sheet->setPos( _x, _y );
	_sheets.push_back( sheet );

	switch ( next ) {
	case NEXT_POS_DOWN:
		_y += sheet->getHeight( ) + SHEET_PITCH;
		break;

	case NEXT_POS_RIGHT:
		_x += sheet->getWidth( ) + SHEET_PITCH;
		_y  = DEFAULT_Y;
		break;
	}
}