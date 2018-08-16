#include "CharacterSelectViewer.h"
#include "CharacterSelectProcessor.h"
#include "Button.h"
#include "Image.h"

#include "Drawer.h"
#include <vector>

CharacterSelectViewer::CharacterSelectViewer( CharacterSelectProcessorConstPtr processor ) :
_processor( processor ) {
}

CharacterSelectViewer::~CharacterSelectViewer( ) {
}

void CharacterSelectViewer::update( ) {
	std::vector< ButtonPtr > buttons = _processor->getButton( );
	for ( ButtonPtr button : buttons ) {
		ImageConstPtr image = button->getImage( );
		image->draw( );
	}
}