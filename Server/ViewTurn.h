#pragma once
#include "smart_ptr.h"

PTR( Turn );
PTR( Sheet );

class ViewTurn {
public:
	ViewTurn( TurnConstPtr turn );
	virtual ~ViewTurn( );

public:
	void updateSheet( );

public:
	SheetPtr getSheet( ) const;

private:
	TurnConstPtr _turn;
	SheetPtr _sheet;
};

