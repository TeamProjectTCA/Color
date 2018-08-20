#pragma once
#include "smart_ptr.h"
#include <string>
#include <list>

PTR( Command );
PTR( Log );
PTR( CommandWord );
PTR( CommandListener );
PTR( Sheet );

class Command {
public:
	Command( LogPtr log );
	virtual ~Command( );

public:
	void update( );

private:
	void executeCommand( );
	void updateSheet( );

public:
	void addListener( CommandListenerPtr listener );

public:
	SheetPtr getSheet( ) const;

private:
	std::string _input;
	std::list< CommandListenerPtr > _listener;

	CommandWordPtr _word;
	LogPtr _log;
	SheetPtr _sheet;
};
