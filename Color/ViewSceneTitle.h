#pragma once
#include "smart_ptr.h"

PTR ( ViewSceneTitle );
PTR ( Drawer );

class ViewSceneTitle {
public:
	ViewSceneTitle ( );
	virtual ~ViewSceneTitle ( );

public:
	void update ( );

private:
	int _bg_image;
	int _title_image;

	DrawerPtr _drawer;
};

