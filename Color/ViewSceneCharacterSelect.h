#pragma once
#include "smart_ptr.h"

PTR ( ViewSceneCharacterSelect );
PTR ( Drawer );

class ViewSceneCharacterSelect {
public:
	ViewSceneCharacterSelect ( );
	virtual ~ViewSceneCharacterSelect ( );

public:
	void update ( );

private:
	DrawerPtr _drawer;
};