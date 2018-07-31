#include "NWOption.h"
#include "NWOptionProcessor.h"
#include "NWOptionViewer.h"

NWOption::NWOption( ) {
	_processor = NWOptionProcessorPtr( new NWOptionProcessor );
	_viewer = NWOptionViewerPtr( new NWOptionViewer( _processor ) );
}

NWOption::~NWOption( ) {
}

void NWOption::update( ) {
	_processor->update( );
	_viewer->update( );
}