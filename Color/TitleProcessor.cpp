#include "TitleProcessor.h"
#include "Button.h"
#include "Vector.h"
#include "Image.h"
#include "SceneChanger.h"

#include "SceneManager.h"
#include "Manager.h"

const char START_BUTTON_DEFAULT_IMAGE[ ] = "Button/Start.png";
const char START_BUTTON_CLICKED_IMAGE[ ] = "Button/StartClick.png";
const char BACK_BUTTON_DEFAULT_IMAGE[ ] = "Button/Option.png";
const char BACK_BUTTON_CLICKED_IMAGE[ ] = "Button/OptionClick.png";

TitleProcessor::TitleProcessor( ) {
	ManagerPtr manager = Manager::getInstance( );
	int width = manager->getScreenWidth( );
	int height = manager->getScreenHeight( );

	_bg_pos = Vector( width / 2, height / 2 );
	_logo_pos = Vector( width / 2, height / 4 );

	//button
	ButtonPtr start_button( new Button( Vector( width / 2, height / 8 * 5 ) ) );
	start_button->setDefaultImagePath( START_BUTTON_DEFAULT_IMAGE );
	start_button->setClickedImagePath( START_BUTTON_CLICKED_IMAGE );
	SceneChangerPtr next( new SceneChanger( SCENE_CHARACTERSELECT ) );
	start_button->setEvent( next );

	ButtonPtr option_button( new Button( Vector( width / 2, height / 6 * 5 ) ) );
	option_button->setDefaultImagePath( BACK_BUTTON_DEFAULT_IMAGE );
	option_button->setClickedImagePath( BACK_BUTTON_CLICKED_IMAGE );
	SceneChangerPtr option( new SceneChanger( SCENE_NWOPTION ) );
	option_button->setEvent( next );

	_button.push_back( start_button );
	_button.push_back( option_button );
}


TitleProcessor::~TitleProcessor( ) {
}

void TitleProcessor::update( ) {
	for ( ButtonPtr button : _button ) {
		button->update( );
	}
}

Vector TitleProcessor::getBgPos( ) const {
	return _bg_pos;
}

Vector TitleProcessor::getLogoPos( ) const {
	return _logo_pos;
}

const std::vector< ButtonPtr >& TitleProcessor::getButton( ) const {
	return _button;
}