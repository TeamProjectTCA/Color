#include "Result.h"
#include "ResultProcessor.h"
#include "Viewer.h"

Result::Result( ViewerPtr viewer ) {
	_process = ResultProcessorPtr( new ResultProcessor( ) );
	viewer->addDrawer( _process );
}

Result::~Result( ) {
}

void Result::update( ) {
	_process->update( );
}