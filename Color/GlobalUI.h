#pragma once
#include "Area.h"

class GlobalUI : public Area {
public:
	GlobalUI( const Vector ORIGIN_POS );
	virtual ~GlobalUI( );

public:
	void draw( ) const;

public:
	void setTurn( int turn );

public:
	Vector getGlobalImagePos( ) const;

private:
	bool _full_hd;
	int _turn;
};