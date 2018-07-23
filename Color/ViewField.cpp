#include "ViewField.h"
#include "drawer.h"


const int WIDTH = 1280;
const int HEIGHT = 720;
const int COL = 6;
const int ROW = 6;

const char GREENMAS_IMAGE[ ] = "green_mas";
const char WHITEMAS_IMAGE[ ] = "white_mas";

ViewField::ViewField( ) {
	_drawer = Drawer::getTask( );

	//_mas_handle[ 0 ] = _drawer->getImage( GREENMAS_IMAGE );
	//_mas_handle[ 1 ] = _drawer->getImage( WHITEMAS_IMAGE );
}


ViewField::~ViewField( ) {
}

void ViewField::update( ) {
	drawField( );
}

void ViewField::drawField( ) const {
	//const int MAS_SIZE = 100;
	//const Vector ADJUST_POS = Vector( ( WIDTH - MAS_SIZE * ROW ) * 0.9, ( HEIGHT - MAS_SIZE * ROW ) / 2 );

	//for ( int i = 0; i < COL * ROW; i++ ) {
	//	int x = i % COL;
	//	int y = i / COL;
	//	_drawer->drawExtendGraph( x   * MAS_SIZE + ADJUST_POS.x, y   * MAS_SIZE + ADJUST_POS.y,
	//		( x + 1 ) * MAS_SIZE + ADJUST_POS.x, ( y + 1 ) * MAS_SIZE + ADJUST_POS.y,
	//							  _mas_handle[ ( x + y ) % 2 ], true );
	//}

}