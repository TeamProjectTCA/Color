#include "CharacterSelectViewer.h"
#include "Drawer.h"

CharacterSelectViewer::CharacterSelectViewer( CharacterSelectProcessorPtr character_select ) :
	_scene_character_select( character_select ) {
	_drawer = Drawer::getTask( );
}

CharacterSelectViewer::~CharacterSelectViewer( ) {
}

void CharacterSelectViewer::update( ) {
	_drawer->drawString( 10, 10, "SceneCharacterSelect", 0xff0000 );
	_drawer->flip( );
}