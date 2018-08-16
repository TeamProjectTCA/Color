#pragma once
#include "smart_ptr.h"


PTR( ViewPaint );
PTR( PaintTile );
PTR( Sheet );

class ViewPaint {
public:
	ViewPaint( PaintTileConstPtr paint );
	virtual ~ViewPaint( );

public:
	void updateSheet( );

public:
	SheetPtr getSheet( ) const;

private:
	PaintTileConstPtr _paint;
	SheetPtr _sheet;
};