#pragma once
#include "smart_ptr.h"

PTR( NWOptionViewer );
PTR( NWOptionProcessor );

class NWOptionViewer {
public:
	NWOptionViewer( NWOptionProcessorConstPtr processor );
	virtual ~NWOptionViewer( );

public:
	void update( );

private:
	void drawNowIP( ) const;
	void drawNewIP( ) const;

private:
	NWOptionProcessorConstPtr _processor;
};

