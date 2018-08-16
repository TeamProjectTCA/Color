#include "ViewPaint.h"
#include "PaintTile.h"
#include "Sheet.h"

const int SHEET_ROW = 3;
const int SHEET_TAG_PITCH = 100;
const int SHEET_VALUE_PITCH = 200;

ViewPaint::ViewPaint( PaintTileConstPtr paint ) :
_paint( paint ) {
	_sheet = SheetPtr( new Sheet( SHEET_ROW ) );
	_sheet->addCol( SHEET_TAG_PITCH );
	_sheet->addCol( SHEET_VALUE_PITCH );
	_sheet->write( 0, 0, "PLAYER" );
	_sheet->write( 0, 1, "0" );
	_sheet->write( 0, 2, "1" );
	_sheet->write( 1, 0, "PAINTCOUNT" );

	updateSheet( );
}


ViewPaint::~ViewPaint( ) {
}

void ViewPaint::updateSheet( ) {
	_sheet->write( 1, 1, std::to_string( _paint->getPaintCount( 0 ) ) );
	_sheet->write( 1, 2, std::to_string( _paint->getPaintCount( 1 ) ) );
}

SheetPtr ViewPaint::getSheet( ) const {
	return _sheet;
}