#pragma once
#include "smart_ptr.h"
#include <string>
#include <list>

PTR( Command );
PTR( Log );
PTR( CommandWord );
PTR( CommandListener );

class Command {
public:
	Command( LogPtr log );
	virtual ~Command( );

public:
	void update( );

private:
	void executeCommand( );

public:
	void addListener( CommandListenerPtr listener );

public:
	std::string getInputString( ) const;

private:
	std::string _input;
	std::list< CommandListenerPtr > _listener;

	CommandWordPtr _word;
	LogPtr _log;
};

