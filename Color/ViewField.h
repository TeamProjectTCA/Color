#pragma once
#include "smart_ptr.h"

PTR( ViewField );
PTR( Field );

class ViewField {
public:
	ViewField( FieldConstPtr field );
	virtual ~ViewField( );

public:
	void draw( ) const;

private:
	FieldConstPtr _field;
};

