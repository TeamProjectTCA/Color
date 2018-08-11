#include "TitleViewer.h"
#include "TitleProcessor.h"
#include "Button.h"
#include "Image.h"

#include "Drawer.h"
#include <vector>

const char BACKGROUND_IMAGE[ ] = "Title/back_001.png";
const char TITLE_IMAGE[ ] = "Title/title.png";

TitleViewer::TitleViewer( TitleProcessorConstPtr processor ) :
_processor( processor ) {
	_drawer = Drawer::getTask( );

	_bg_image = _drawer->getImage( BACKGROUND_IMAGE );
	_title_image = _drawer->getImage( TITLE_IMAGE );
}

TitleViewer::~TitleViewer( ) {
}

void TitleViewer::update( ) {
	_drawer = Drawer::getTask( );
	_drawer->drawString( 10, 10, "SceneTitle", 0xff0000 );
	drawBackGround( );
	drawTitleLogo( );
	drawButton( );

	_drawer->flip( );
}

void TitleViewer::drawTitleLogo( ) const {
	Vector logo_pos = _processor->getLogoPos( );
	_title_image->setCentral( true );
	_title_image->setPos( ( int )logo_pos.x, ( int )logo_pos.y );
	_title_image->draw( );
}

void TitleViewer::drawBackGround( ) const {
	Vector bg_pos = _processor->getBgPos( );
	_bg_image->setCentral( true );
	_bg_image->setPos( ( int )bg_pos.x, ( int )bg_pos.y );
	_bg_image->draw( );
}

void TitleViewer::drawButton( ) const {
	std::vector< ButtonPtr > buttons = _processor->getButton( );
	for ( ButtonPtr button : buttons ) {
		ImageConstPtr image = button->getImage( );
		image->draw( );
	}
}