#include "ShowTurn.h"
#include "Drawer.h"

ShowTurn::ShowTurn( ):
_turn( -1 ) {
}


ShowTurn::~ShowTurn( ) {
}

void ShowTurn::draw( ) const {
	DrawerPtr drawer = Drawer::getTask( );
	if ( _turn >= 0 ) {
		drawer->drawString( 10, 30, "c‚è" + std::to_string( _turn ) + "ƒ^[ƒ“", 0xff0000 );
	}
}

void ShowTurn::setTurn( int turn ) {
	_turn = turn;
}