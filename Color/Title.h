#pragma once
#include "Scene.h"
#include <vector>

PTR( Title );
PTR( Button );
PTR( Image );

class Title : public Scene {
public:
	Title( );
	virtual ~Title( );

public:
	void update( );
	void draw( ) const;

private:
	ImagePtr _bg;
	ImagePtr _logo;
	std::vector< ButtonPtr > _button;
};