#include "StartButtonViewer.h"
#include "StartButton.h"
#include "Drawer.h"
#include "Image.h"

const char NORMAL_BUTTON[ ] = "Button/StartButtonNormal.png";
const char PUSH_BUTTON[ ] = "Button/StartButtonPush.png";

StartButtonViewer::StartButtonViewer( StartButtonPtr start_button ) :
_start_button( start_button ) {
	_drawer = Drawer::getTask( );

	_normal_start_button = _drawer->getImage( NORMAL_BUTTON );
	_push_start_button = _drawer->getImage( PUSH_BUTTON );
}


StartButtonViewer::~StartButtonViewer( ) {
}

void StartButtonViewer::update( ) {
	if ( _start_button->getButtonState( ) == StartButton::BUTTON_STATE_NORMAL ) {
		drawNormalButton( );
	}
	if ( _start_button->getButtonState( ) == StartButton::BUTTON_STATE_PUSH ) {
		drawPushButton( );
	}
}

void StartButtonViewer::drawNormalButton( ) const {
	Vector button_pos = _start_button->getButtonPos( );
	_normal_start_button->setCentral( true );
	_normal_start_button->setPos( ( int ) button_pos.x, ( int ) button_pos.y );
	_normal_start_button->draw( );
}

void StartButtonViewer::drawPushButton( ) const {
	Vector button_pos = _start_button->getButtonPos( );
	_push_start_button->setCentral( true );
	_push_start_button->setPos( ( int ) button_pos.x, ( int ) button_pos.y );
	_push_start_button->draw( );
}