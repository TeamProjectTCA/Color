#include "FieldViewer.h"
#include "Vector.h"
#include "drawer.h"
#include "image.h"

const int WIDTH = 1280;
const int HEIGHT = 720;
const int COL = 6;
const int ROW = 6;

const char GREENMAS_IMAGE[ ] = "Field/green_mas.png";
const char WHITEMAS_IMAGE[ ] = "Field/white_mas.png";

FieldViewer::FieldViewer( ) {
	_drawer = Drawer::getTask( );

	//_mas_handle[ 0 ] = _drawer->getImage( GREENMAS_IMAGE );
	//_mas_handle[ 1 ] = _drawer->getImage( WHITEMAS_IMAGE );
}


FieldViewer::~FieldViewer( ) {
}

void FieldViewer::update( ) {
	drawField( );
}

void FieldViewer::drawField( ) const {
	//const int MAS_SIZE = 100;
	//const Vector ADJUST_POS = Vector( ( WIDTH - MAS_SIZE * ROW ) * 0.9, ( HEIGHT - MAS_SIZE * ROW ) / 2 );
	//
	//for ( int i = 0; i < COL * ROW; i++ ) {
	//	int x = i % COL;
	//	int y = i / COL;
	//	if ( ( x + y ) % 2 ) {
	//		_mas_handle[ 0 ]->setPos( x       * MAS_SIZE + ADJUST_POS.x,   y       * MAS_SIZE + ADJUST_POS.y,
	//			                    ( x + 1 ) * MAS_SIZE + ADJUST_POS.x, ( y + 1 ) * MAS_SIZE + ADJUST_POS.y );
	//		_mas_handle[ 0 ]->setRect( 0, 0, 52, 52 );
	//		_mas_handle[ 0 ]->draw( );
	//	} else {
	//		_mas_handle[ 1 ]->setPos( x       * MAS_SIZE + ADJUST_POS.x,   y       * MAS_SIZE + ADJUST_POS.y,
	//		                     	( x + 1 ) * MAS_SIZE + ADJUST_POS.x, ( y + 1 ) * MAS_SIZE + ADJUST_POS.y );
	//		_mas_handle[ 1 ]->setRect( 0, 0, 52, 52 );
	//		_mas_handle[ 1 ]->draw( );
	//	}
	//}

}