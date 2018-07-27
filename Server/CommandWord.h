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

public:
	int getTokenCount( ) const;
	std::string getTokenString( int idx ) const;
	int getTokenValue( int idx ) const;

public:
	std::string makeUnknownError( ) const;
	std::string makeError( int error_idx, std::string cause ) const;

private:
	std::vector< std::string > _word;
};

