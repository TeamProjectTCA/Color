#include "Command.h"
#include "Keyboard.h"
#include "CommandWord.h"
#include "Sheet.h"

Command::Command( LogPtr log ) :
_log( log ) {
	_word = CommandWordPtr( new CommandWord( ) );
}

Command::~Command( ) {
}

void Command::update( ) {
	KeyboardPtr keyboard = Keyboard::getTask( );

	// input
	std::string input = keyboard->getString( );
	if ( keyboard->getKeyDown( input ) ) {
		_input.push_back( input[ 0 ] );
	}

	// back space
	if ( keyboard->getBackSpace( ) == 1 || keyboard->getBackSpace( ) > 30 ) {
		if ( !_input.empty( ) ) {
			_input.pop_back( );
		}
	}

	// enter
	if ( keyboard->getKeyDown( "ENTER" ) ) {
		_word->add( _input );
		std::string( ).swap( _input );
	}
}

std::string Command::getInputString( ) const {
	return _input;
}