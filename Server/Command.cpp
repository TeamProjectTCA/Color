#include "Command.h"
#include "Keyboard.h"
#include "CommandWord.h"
#include "CommandListener.h"
#include "Log.h"
#include "Sheet.h"

const int TAG_PITCH = 80;
const int VALUE_PITCH = 420;

const short int CONTINUITY_TIME = 30;
const short int MAX_CHARACTER = 30;

Command::Command( LogPtr log ) :
_log( log ) {
	_word = CommandWordPtr( new CommandWord( ) );

	_sheet = SheetPtr( new Sheet( 1 ) );
	_sheet->addCol( TAG_PITCH );
	_sheet->addCol( VALUE_PITCH );
	_sheet->write( 0, 0, "COMMAND" );

	updateSheet( );
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
	if ( keyboard->getKeyDown( "ENTER" ) ) {
		_word->add( _input );
		std::string( ).swap( _input );

		executeCommand( );
	}

	updateSheet( );
}

void Command::executeCommand( ) {
	for ( CommandListenerPtr listener : _listener ) {
		CommandListener::RESULT result = listener->command( _word );
		switch ( result ) {
		case CommandListener::RESULT_DONE:
			return;

		case CommandListener::RESULT_ERROR:
			_log->add( listener->getErrorLog( ) );
			return;

		case CommandListener::RESULT_THROW:
			break;
		}
	}

	// throw
	_log->add( _word->makeUnknownError( ) );
}

void Command::updateSheet( ) {
	_sheet->write( 1, 0, _input );
}

void Command::addListener( CommandListenerPtr listener ) {
	_listener.push_back( listener );
}

SheetPtr Command::getSheet( ) const {
	return _sheet;
}