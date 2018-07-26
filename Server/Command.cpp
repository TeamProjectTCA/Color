#include "Command.h"
#include "Keyboard.h"
#include "CommandWord.h"
#include "CommandListener.h"

const short int CONTINUITY_TIME = 30;
const short int MAX_CHARACTER = 30;

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
	int state = keyboard->getKeyState( input );

	if ( ( state == 1 || state > CONTINUITY_TIME ) && _input.length( ) < MAX_CHARACTER ) {
		_input.push_back( input[ 0 ] );
	}

	// back space
	int back_space = keyboard->getKeyState( "BACK" );
	if ( back_space == 1 || back_space > CONTINUITY_TIME ) {
		if ( !_input.empty( ) ) {
			_input.pop_back( );
		}
	}

	// enter
	if ( keyboard->getKeyUp( "ENTER" ) ) {
		_word->add( _input );
		std::string( ).swap( _input );

		executeCommand( );
	}
}

void Command::executeCommand( ) {
	for ( CommandListenerPtr listener : _listener ) {
		listener->command( _word );
	}
}

void Command::addListener( CommandListenerPtr listener ) {
	_listener.push_back( listener );
}

std::string Command::getInputString( ) const {
	return _input;
}