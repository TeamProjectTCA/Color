#pragma once
#include "smart_ptr.h"
#include <string>
#include <vector>

PTR( CommandWord );

class CommandWord {
public:
	CommandWord( );
	virtual ~CommandWord( );

public:
	void add( std::string command );

private:
	std::vector< std::string > _word;
};

