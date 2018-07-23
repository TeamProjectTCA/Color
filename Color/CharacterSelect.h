#pragma once
#include "Scene.h"
#include "smart_ptr.h"

PTR( CharacterSelect );
PTR( CharacterSelectProcessor );
PTR( CharacterSelectViewer );

class CharacterSelect : public Scene {
public:
	CharacterSelect( );
	virtual ~CharacterSelect( );

public:
	void update( );

private:
	CharacterSelectProcessorPtr _process;
	CharacterSelectViewerPtr _viewer;
};