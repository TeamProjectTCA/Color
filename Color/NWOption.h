#pragma once
#include "Scene.h"
#include <string>

PTR( NWOption );
PTR( NWOptionProcessor );
PTR( NWOptionViewer );

class NWOption : public Scene {
public:
	NWOption( );
	virtual ~NWOption( );

public:
	void update( );

private:
	NWOptionProcessorPtr _processor;
	NWOptionViewerPtr _viewer;
};

