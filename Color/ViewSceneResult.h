#pragma once
#include "smart_ptr.h"

PTR ( ViewSceneResult );
PTR ( Drawer );

class ViewSceneResult {
public:
	ViewSceneResult ( );
	virtual ~ViewSceneResult ( );

public:
	void update ( );

private:
	DrawerPtr _drawer;
};

