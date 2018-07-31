#pragma once
#include "smart_ptr.h"
#include "Vector.h"

PTR( TitleProcessor );
PTR( StartButton );
PTR( OptionButton );

class TitleProcessor {
public:
	TitleProcessor( StartButtonPtr start_button, OptionButtonPtr option_button );
	virtual ~TitleProcessor( );

public:
	void update( );

public:
	Vector getBgPos( ) const;
	Vector getLogoPos( ) const;

private:
	Vector _bg_pos;
	Vector _logo_pos;
	StartButtonPtr _start_button;
	OptionButtonPtr _option_button;
};