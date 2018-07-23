#include "ResultViewer.h"
#include "Drawer.h"


ResultViewer::ResultViewer( ResultProcessorPtr result ) :
_scene_result( result ) {
	_drawer = Drawer::getTask( );
}

ResultViewer::~ResultViewer( ) {
}

void ResultViewer::update( ) {
	_drawer->drawString( 10, 10, "SceneResult", 0xff0000 );
	_drawer->flip( );
}