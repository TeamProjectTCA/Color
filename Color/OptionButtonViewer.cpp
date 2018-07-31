#include "OptionButtonViewer.h"
#include "OptionButton.h"
#include "Drawer.h"
#include "Image.h"

const char NORMAL_BUTTON[ ] = "Button/OptionButtonNormal.png";
const char PUSH_BUTTON[ ] = "Button/OptionButtonPush.png";

OptionButtonViewer::OptionButtonViewer( OptionButtonPtr option_button ) :
_option_button( option_button ) {
	_drawer = Drawer::getTask( );

	_normal_option_button = _drawer->getImage( NORMAL_BUTTON );
	_push_option_button = _drawer->getImage( PUSH_BUTTON );
}


OptionButtonViewer::~OptionButtonViewer( ) {
}

void OptionButtonViewer::update( ) {
	if ( _option_button->getButtonState( ) == OptionButton::BUTTON_STATE_NORMAL ) {
		drawNormalButton( );
	}
	if ( _option_button->getButtonState( ) == OptionButton::BUTTON_STATE_PUSH ) {
		drawPushButton( );
	}
}

void OptionButtonViewer::drawNormalButton( ) const {
	Vector button_pos = _option_button->getButtonPos( );
	_normal_option_button->setCentral( true );
	_normal_option_button->setPos( ( int ) button_pos.x, ( int ) button_pos.y );
	_normal_option_button->draw( );
}

void OptionButtonViewer::drawPushButton( ) const {
	Vector button_pos = _option_button->getButtonPos( );
	_push_option_button->setCentral( true );
	_push_option_button->setPos( ( int ) button_pos.x, ( int ) button_pos.y );
	_push_option_button->draw( );
}