#include "Test.h"
#include "CommandWord.h"


Test::Test()
{
}


Test::~Test()
{
}

CommandListener::RESULT Test::command( CommandWordConstPtr word ) {
	if ( word->getTokenCount( ) < 1 ) {
		return RESULT_THROW;
	}

	if ( word->getTokenString( 0 ) != "abc" ) {
		return RESULT_THROW;
	}

	if ( word->getTokenCount( ) < 2 ) {
		return RESULT_THROW;
	}

	if ( word->getTokenString( 1 ) != "def" ) {
		addErrorLog( word->makeError( 1, " [ " + word->getTokenString( 1 ) + " ] is spell miss" ) );
		return RESULT_ERROR;
	}

	return RESULT_DONE;
}
