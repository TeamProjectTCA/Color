#pragma once
#include "Scene.h"
#include "smart_ptr.h"

PTR( CharacterSelectViewer );
PTR( CharacterSelectProcessor );
PTR( Drawer );

class CharacterSelectViewer  {
public:
	CharacterSelectViewer( CharacterSelectProcessorConstPtr character_select );
	virtual ~CharacterSelectViewer( );

public:
	void update( );

private:
	DrawerPtr _drawer;
	CharacterSelectProcessorConstPtr _scene_character_select;
};