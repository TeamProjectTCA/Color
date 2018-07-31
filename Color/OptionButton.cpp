#include "OptionButton.h"
#include "Manager.h"
#include "SceneManager.h"
#include "Keyboard.h"
#include "Mouse.h"

OptionButton::OptionButton( ) :
_state( BUTTON_STATE_NORMAL ) {
	ManagerPtr manager = Manager::getInstance( );
	int width = manager->getScreenWidth( );
	int height = manager->getScreenHeight( );

	_button_pos = Vector( width / 2, height / 6 * 5 );

	setCollider( _button_pos.x - 192, _button_pos.y - 48, _button_pos.x + 192, _button_pos.y + 48 );
}


OptionButton::~OptionButton( ) {
}

void OptionButton::update( ) {
	MousePtr mouse = Mouse::getTask( );
	Vector mouse_pos = mouse->getPoint( );

	if ( mouse->getClickingLeft( ) ) {
		click( mouse_pos );
	} else {
		if ( _state == BUTTON_STATE_PUSH ) {
			SceneManagerPtr sence_manager = SceneManager::getTask( );
			sence_manager->setNextScene( SCENE_NWOPTION );
		}
		_state = BUTTON_STATE_NORMAL;
	}
}

OptionButton::BUTTON_STATE OptionButton::getButtonState( ) const {
	return _state;
}

void OptionButton::click( Vector mouse ) {
	_state = BUTTON_STATE_NORMAL;

	if ( _lx <= mouse.x && mouse.x <= _rx &&
		 _ly <= mouse.y && mouse.y <= _ry ) {
		_state = BUTTON_STATE_PUSH;
	}
}

void OptionButton::setCollider( float lx, float ly, float rx, float ry ) {
	_lx = lx;
	_ly = ly;
	_rx = rx;
	_ry = ry;
}

Vector OptionButton::getButtonPos( ) const {
	return _button_pos;
}