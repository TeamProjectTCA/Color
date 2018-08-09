#pragma once
#include "smart_ptr.h"
#include <vector>

PTR( Button );

class CharacterSelectProcessor {
public:
	CharacterSelectProcessor( );
	virtual ~CharacterSelectProcessor( );

public:
	void update( );

public:
	const std::vector< ButtonPtr > &getButton( ) const;

private:
	std::vector< ButtonPtr > _button;
};