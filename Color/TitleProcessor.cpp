#include "TitleProcessor.h"
#include "Manager.h"
#include "SceneManager.h"
#include "StartButton.h"
#include "OptionButton.h"
#include "Keyboard.h"
#include "Mouse.h"

TitleProcessor::TitleProcessor( StartButtonPtr start_button, OptionButtonPtr option_button ):
_start_button( start_button ),
_option_button( option_button ) {
	ManagerPtr manager = Manager::getInstance( );
	int width = manager->getScreenWidth( );
	int height = manager->getScreenHeight( );

	_bg_pos = Vector( width / 2, height / 2 );
	_logo_pos = Vector( width / 2, height / 4 );
}


TitleProcessor::~TitleProcessor( ) {
}

void TitleProcessor::update( ) {
	_start_button->update( );
	_option_button->update( );

	KeyboardPtr keyboard = Keyboard::getTask( );

	if ( keyboard->getKeyDown( "z" ) ) {
		SceneManagerPtr sence_manager = SceneManager::getTask( );
		sence_manager->setNextScene( SCENE_CHARACTERSELECT );
	}

	if ( keyboard->getKeyDown( "o" ) ) {
		SceneManagerPtr sence_manager = SceneManager::getTask( );
		sence_manager->setNextScene( SCENE_NWOPTION );
	}
}

Vector TitleProcessor::getBgPos( ) const {
	return _bg_pos;
}

Vector TitleProcessor::getLogoPos( ) const {
	return _logo_pos;
}