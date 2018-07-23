#pragma once
#include "smart_ptr.h"
#include <list>

PTR( Table );
PTR( Sheet );

class Table {
public:
	enum NEXT_POS {
		NEXT_POS_DOWN,
		NEXT_POS_RIGHT
	};

public:
	Table( );
	virtual ~Table( );

public:
	void draw( ) const;

public:
	void add( SheetPtr sheet, NEXT_POS next );

private:
	float _x;
	float _y;

	std::list< SheetPtr > _sheets;
};

