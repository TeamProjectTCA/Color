#include "CharacterSelectProcessor.h"
#include "Button.h"
#include "Vector.h"
#include "Image.h"
#include "SceneChanger.h"

#include "SceneManager.h"
#include "Manager.h"

const char START_BUTTON_DEFAULT_IMAGE[ ] = "Button/StartButtonNormal.png";
const char START_BUTTON_CLICKED_IMAGE[ ] = "Button/StartButtonPush.png";
const char BACK_BUTTON_DEFAULT_IMAGE[ ] = "Button/Return.png";
const char BACK_BUTTON_CLICKED_IMAGE[ ] = "Button/ReturnClick.png";

CharacterSelectProcessor::CharacterSelectProcessor( ) {
	ManagerPtr manager = Manager::getInstance( );
	int width  = manager->getScreenWidth( );
	int height = manager->getScreenHeight( );

	// start button
	ButtonPtr start_button( new Button( Vector( width / 2, height / 2 ) ) );
	start_button->setDefaultImagePath( START_BUTTON_DEFAULT_IMAGE );
	start_button->setClickedImagePath( START_BUTTON_CLICKED_IMAGE );
	SceneChangerPtr next( new SceneChanger( SCENE_GAME ) );
	start_button->setEvent( next );

	// back button
	ButtonPtr back_button( new Button( Vector( 150, 100 ) ) );
	back_button->setDefaultImagePath( BACK_BUTTON_DEFAULT_IMAGE );
	back_button->setClickedImagePath( BACK_BUTTON_CLICKED_IMAGE );
	SceneChangerPtr back( new SceneChanger( SCENE_TITLE ) );
	back_button->setEvent( back );

	_button.push_back( start_button );
	_button.push_back( back_button );
}

CharacterSelectProcessor::~CharacterSelectProcessor( ) {
}

void CharacterSelectProcessor::update( ) {
	for ( ButtonPtr button : _button ) {
		button->update( );
	}
}

const std::vector< ButtonPtr >& CharacterSelectProcessor::getButton( ) const {
	return _button;
}