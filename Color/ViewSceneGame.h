#pragma once
#include "smart_ptr.h"

PTR ( ViewSceneGame );
PTR ( Drawer );

class ViewSceneGame {
public:
	ViewSceneGame ( );
	virtual ~ViewSceneGame ( );

public:
	void update ( );

private:
	DrawerPtr _drawer;
};

