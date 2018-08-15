#pragma once
#include "smart_ptr.h"

PTR( ViewTurn );
PTR( Turn );
PTR( Sheet );

class ViewTurn {
public:
	ViewTurn( TurnConstPtr turn );
	virtual ~ViewTurn( );

public:
	void initialize( );

public:
	void updateSheet( );

public:
	SheetPtr getSheet( ) const;

private:
	TurnConstPtr _turn;
	SheetPtr _sheet;
};

