#include "PlayerUI.h"
#include "Manager.h"
#include "Drawer.h"

const Vector DEFAULT_PLAYER_IMAGE = Vector( 150, 150 );

PlayerUI::PlayerUI( const Vector ORIGIN_POS ) :
Area( ORIGIN_POS ),
_full_hd( false ),
_paint_count( 0 ) {
	ManagerPtr manager = Manager::getInstance( );
	if ( manager->getScreenHeight( ) == 1080 ) {
		_full_hd = true;
	}
}

PlayerUI::~PlayerUI( ) {
}

void PlayerUI::draw( ) const {
	DrawerPtr drawer = Drawer::getTask( );
	Vector pos = getPlayerImagePos( );

	drawer->drawCircle( ( float ) pos.x, ( float ) pos.y, 10, 0x00ff00, true );

	drawer->drawString( ( float ) pos.x - 100, ( float ) pos.y + 100, "プレイヤーは" + std::to_string( _paint_count ) + "マスを塗った", 0xff0000 );
}

void PlayerUI::setPaintCount( int paint_count ) {
	_paint_count = paint_count;
}

Vector PlayerUI::getPlayerImagePos( ) const {
	Vector origin = getOrigin( );
	Vector pos = DEFAULT_PLAYER_IMAGE;
	if ( _full_hd ) {
		pos *= 1.5;
	}

	return pos + origin;
}