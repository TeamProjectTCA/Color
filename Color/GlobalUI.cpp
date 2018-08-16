#include "GlobalUI.h"
#include "Manager.h"
#include "Drawer.h"

const Vector DEFAULT_TURN_IMAGE = Vector( 10, 30 );

GlobalUI::GlobalUI( const Vector ORIGIN_POS ):
Area( ORIGIN_POS ),
_turn( -1 ) {
	ManagerPtr manager = Manager::getInstance( );
	if ( manager->getScreenHeight( ) == 1080 ) {
		_full_hd = true;
	}
}


GlobalUI::~GlobalUI( ) {
}

void GlobalUI::draw( ) const {
	DrawerPtr drawer = Drawer::getTask( );
	Vector pos = getGlobalImagePos( );
	if ( _turn >= 0 ) {
		drawer->drawString( ( float ) pos.x, ( float ) pos.y, "écÇË" + std::to_string( _turn ) + "É^Å[Éì", 0xff0000 );
	}
}

void GlobalUI::setTurn( int turn ) {
	_turn = turn;
}

Vector GlobalUI::getGlobalImagePos( ) const {
	Vector origin = getOrigin( );
	Vector pos = DEFAULT_TURN_IMAGE;
	if ( _full_hd ) {
		pos *= 1.5;
	}

	return pos + origin;
}