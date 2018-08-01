#pragma once
#include "smart_ptr.h"

PTR( ViewChara );
PTR( Chara );

class ViewChara {
public:
	ViewChara( CharaConstPtr player );
	virtual ~ViewChara( );

public:
	void draw( ) const;

private:
	CharaConstPtr _player;
};

