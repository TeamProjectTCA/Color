#pragma once
#include "GameDrawer.h"

class ShowTurn : public GameDrawer {
public:
	ShowTurn( );
	virtual ~ShowTurn( );

public:
	void draw( ) const;

public:
	void setTurn( int turn );

private:
	int _turn;
};