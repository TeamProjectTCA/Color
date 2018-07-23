#include "Title.h"
#include "TitleProcessor.h"
#include "TitleViewer.h"

Title::Title( ) {
	_process = TitleProcessorPtr( new TitleProcessor( ) );
	_viewer = TitleViewerPtr( new TitleViewer( _process ) );
}

Title::~Title( ) {
}

void Title::update( ) {
	_process->update( );
	_viewer->update( );
}
