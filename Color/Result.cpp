#include "Result.h"
#include "ResultProcessor.h"
#include "ResultViewer.h"

Result::Result( ) {
	_process = ResultProcessorPtr( new ResultProcessor( ) );
	_viewer = ResultViewerPtr( new ResultViewer( _process ) );
}

Result::~Result( ) {
}

void Result::update( ) {
	_process->update( );
	_viewer->update( );
}