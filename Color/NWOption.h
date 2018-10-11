#pragma once
#include "Scene.h"
#include "Vector.h"
#include <string>

PTR( NWOption );

class NWOption : public Scene {
private:
	enum ACT {
		ACT_WAIT,
		ACT_INPUT,
		ACT_DELETE,
		ACT_ENTER
	};

public:
	NWOption( );
	virtual ~NWOption( );

public:
	void update( );
	void draw( ) const;

private:
	void updateAct( );
	void actOnInput( );
	void actOnDelete( );
	void actOnEnter( );

private:
	std::string _new_ip;
	ACT _act;
};

