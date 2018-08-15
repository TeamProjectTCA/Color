#include "Title.h"
#include "TitleProcessor.h"
#include "Viewer.h"

Title::Title( ViewerPtr viewer ) {
	_process = TitleProcessorPtr( new TitleProcessor );
	viewer->addDrawer( _process );
}

Title::~Title( ) {
}

void Title::update( ) {
	_process->update( );
}
