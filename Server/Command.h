#pragma once
#include "smart_ptr.h"
#include <string>

PTR( Command );
PTR( Log );
PTR( CommandWord );
PTR( Sheet );

class Command {
public:
	Command( LogPtr log );
	virtual ~Command( );

public:
	void update( );

public:
	std::string getInputString( ) const;

private:
	std::string _input;

	CommandWordPtr _word;
	LogPtr _log;
};

