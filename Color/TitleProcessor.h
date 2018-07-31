#pragma once
#include "smart_ptr.h"
#include "Vector.h"

PTR( TitleProcessor );

class TitleProcessor {
public:
	TitleProcessor( );
	virtual ~TitleProcessor( );

public:
	void update( );

public:
	Vector getBgPos( );
	Vector getLogoPos( );

private:
	Vector _bg_pos;
	Vector _logo_pos;
};