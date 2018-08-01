#pragma once
#include "smart_ptr.h"

PTR( ViewPlayerUI );
PTR( PlayerUI );

class ViewPlayerUI {
public:
	ViewPlayerUI( PlayerUIConstPtr player_ui );
	virtual ~ViewPlayerUI( );

public:
	void draw( ) const;

private:
	PlayerUIConstPtr _player_ui;
};

