#pragma once
#include "smart_ptr.h"
#include "Vector.h"
#include <vector>

PTR( TitleProcessor );
PTR( Button );


class TitleProcessor {
public:
	TitleProcessor( );
	virtual ~TitleProcessor( );

public:
	void update( );

public:
	Vector getBgPos( ) const;
	Vector getLogoPos( ) const;
	const std::vector< ButtonPtr > &getButton( ) const;

private:
	Vector _bg_pos;
	Vector _logo_pos;
	std::vector< ButtonPtr > _button;
};