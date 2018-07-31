#include "NWOptionViewer.h"
#include "NWOptionProcessor.h"
#include "Vector.h"
#include "Drawer.h"

NWOptionViewer::NWOptionViewer( NWOptionProcessorConstPtr processor ) :
_processor( processor ) {
}

NWOptionViewer::~NWOptionViewer( ) {
}

void NWOptionViewer::update( ) {
	drawNewIP( );
	drawNowIP( );

	DrawerPtr drawer = Drawer::getTask( );
	drawer->flip( );
}

void NWOptionViewer::drawNowIP( ) const {
	Vector pos = _processor->getNowIPPos( );
	std::string ip = _processor->getNowIP( );

	DrawerPtr drawer = Drawer::getTask( );
	drawer->drawFormatStringCenter( ( float )pos.x, ( float )pos.y, 0xffffff, ip.c_str( ) );
}

void NWOptionViewer::drawNewIP( ) const {
	Vector pos = _processor->getNewIPPos( );
	std::string ip = _processor->getNewIP( );

	DrawerPtr drawer = Drawer::getTask( );
	drawer->drawFormatStringCenter( ( float )pos.x, ( float )pos.y, 0xffffff, ip.c_str( ) );

}