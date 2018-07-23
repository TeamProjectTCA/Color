#include "CharacterSelect.h"
#include "CharacterSelectProcessor.h"
#include "CharacterSelectViewer.h"

CharacterSelect::CharacterSelect( ) {
	_process = CharacterSelectProcessorPtr( new CharacterSelectProcessor( ) );
	_viewer = CharacterSelectViewerPtr( new CharacterSelectViewer( _process ) );

}

CharacterSelect::~CharacterSelect( ) {
}

void CharacterSelect::update( ) {
	_process->update( );
	_viewer->update( );
}