#pragma once
#include "smart_ptr.h"
#include <string>

PTR( CommandListener );
PTR( CommandWord );

class CommandListener {
public:
	enum RESULT {
		RESULT_DONE,
		RESULT_ERROR,
		RESULT_THROW
	};

public:
	CommandListener( );
	virtual ~CommandListener( );

public:
	virtual RESULT command( CommandWordConstPtr word ) = 0;

public:
	void addErrorLog( std::string error );
	std::string getErrorLog( ) const;

private:
	std::string _error;
};

