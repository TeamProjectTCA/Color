#include "Title.h"
#include "TitleProcessor.h"
#include "TitleViewer.h"
#include "StartButton.h"
#include "StartButtonViewer.h"
#include "OptionButton.h"
#include "OptionButtonViewer.h"

Title::Title( ) {
	_start_button = StartButtonPtr( new StartButton( ) );
	_view_start_button = StartButtonViewerPtr( new StartButtonViewer( _start_button ) );
	_option_button = OptionButtonPtr( new OptionButton( ) );
	_view_option_button = OptionButtonViewerPtr( new OptionButtonViewer( _option_button ) );
	_process = TitleProcessorPtr( new TitleProcessor( _start_button, _option_button ) );
	_viewer = TitleViewerPtr( new TitleViewer( _process, _view_start_button, _view_option_button ) );
}

Title::~Title( ) {
}

void Title::update( ) {
	_process->update( );
	_viewer->update( );
}
