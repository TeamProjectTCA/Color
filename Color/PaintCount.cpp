#include "PaintCount.h"
#include "Drawer.h"

PaintCount::PaintCount( ) {
	std::array< int, 2 >( ).swap( _paint_count );
}


PaintCount::~PaintCount( ) {
}

void PaintCount::draw( ) const {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->drawString( 10, 50, "赤プレイヤーは" + std::to_string( _paint_count[ 0 ] ) + "マスを塗った", 0xff0000 );
	drawer->drawString( 10, 70, "青プレイヤーは" + std::to_string( _paint_count[ 1 ] ) + "マスを塗った", 0xff0000 );
	
}

void PaintCount::setPaintCount( int player_num, int paint_count ) {
	_paint_count[ player_num ] = paint_count;
}