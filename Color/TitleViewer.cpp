#include "TitleViewer.h"
#include "TitleProcessor.h"
#include "StartButtonViewer.h"
#include "OptionButtonViewer.h"
#include "Drawer.h"
#include "Image.h"

const char BACKGROUND_IMAGE[ ] = "Title/back_001.png";
const char TITLE_IMAGE[ ] = "Title/title.png";

TitleViewer::TitleViewer( TitleProcessorConstPtr title, StartButtonViewerPtr start_button, OptionButtonViewerPtr option_button ) :
_scene_title( title ),
_view_start_button( start_button ),
_view_option_button( option_button ){
	_drawer = Drawer::getTask( );

	_bg_image = _drawer->getImage( BACKGROUND_IMAGE );
	_title_image = _drawer->getImage( TITLE_IMAGE );
}

TitleViewer::~TitleViewer( ) {
}

void TitleViewer::update( ) {
	_drawer->drawString( 10, 10, "SceneTitle", 0xff0000 );
	drawBackGround( );
	drawTitleLogo( );

	_view_start_button->update( );
	_view_option_button->update( );
	_drawer->flip( );
}

void TitleViewer::drawTitleLogo( ) const {
	Vector logo_pos = _scene_title->getLogoPos( );
	_title_image->setCentral( true );
	_title_image->setPos( ( int )logo_pos.x, ( int )logo_pos.y );
	_title_image->draw( );
}

void TitleViewer::drawBackGround( ) const {
	Vector bg_pos = _scene_title->getBgPos( );
	_bg_image->setCentral( true );
	_bg_image->setPos( ( int )bg_pos.x, ( int )bg_pos.y );
	_bg_image->draw( );
}