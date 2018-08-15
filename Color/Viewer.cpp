#include "Viewer.h"
#include "GameDrawer.h"
#include "Drawer.h"

Viewer::Viewer( ) {
}

Viewer::~Viewer( ) {
}

void Viewer::update( ) {
	for ( GameDrawerConstPtr drawer : _drawer ) {
		drawer->draw( );
	}

	DrawerPtr fw_drawer = Drawer::getTask( );
	fw_drawer->flip( );
}

void Viewer::resetDrawer( ) {
	_drawer.clear( );
}

void Viewer::addDrawer( GameDrawerConstPtr drawer ) {
	_drawer.push_back( drawer );
}
