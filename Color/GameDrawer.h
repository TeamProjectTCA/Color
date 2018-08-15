#pragma once
class GameDrawer {
public:
	GameDrawer( ) { };
	virtual ~GameDrawer( ) { };

public:
	virtual void draw( ) const = 0;
};

