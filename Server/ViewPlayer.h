#pragma once
#include "smart_ptr.h"

PTR( ViewPlayer );
PTR( Player );
PTR( Sheet );

class ViewPlayer {
public:
	ViewPlayer( PlayerConstPtr player );
	virtual ~ViewPlayer( );

public:
	void initialize( );

public:
	void updateSheet( );

public:
	SheetPtr getSheet( ) const;

private:
	PlayerConstPtr _player;
	SheetPtr _sheet;
};

