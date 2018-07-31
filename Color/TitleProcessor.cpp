#include "TitleProcessor.h"
#include "SceneManager.h"
#include "Keyboard.h"
#include "Mouse.h"

const int WIDTH = 1280;
const int HEIGHT = 720;

TitleProcessor::TitleProcessor( ) {
	_bg_pos = Vector( WIDTH / 2, HEIGHT / 2 );
	_logo_pos = Vector( WIDTH / 2, HEIGHT / 4 );
}


TitleProcessor::~TitleProcessor( ) {
}

void TitleProcessor::update( ) {
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

Vector TitleProcessor::getBgPos( ) {
	return _bg_pos;
}

Vector TitleProcessor::getLogoPos( ) {
	return _logo_pos;
}