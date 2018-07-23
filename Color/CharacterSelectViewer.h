#pragma once
#include "Scene.h"
#include "smart_ptr.h"

PTR( CharacterSelectViewer );
PTR( CharacterSelectProcessor );
PTR( Drawer );

class CharacterSelectViewer  {
public:
	CharacterSelectViewer( CharacterSelectProcessorPtr character_select );
	virtual ~CharacterSelectViewer( );

public:
	void update( );

private:
	DrawerPtr _drawer;
	CharacterSelectProcessorPtr _scene_character_select;
};