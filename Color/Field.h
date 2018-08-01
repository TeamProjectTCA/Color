#pragma once
#include "smart_ptr.h"
#include "Area.h"

PTR( Field );

class Field : public Area {
public:
	Field( const Vector ORIGIN_POS );
	virtual ~Field( );

public:
	Vector getCenterPos( ) const;
};

