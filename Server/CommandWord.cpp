#include "CommandWord.h"

CommandWord::CommandWord( ) {
}

CommandWord::~CommandWord( ) {
}

void CommandWord::add( std::string command ) {
	std::vector< std::string >( ).swap( _word );

	while ( true ) {
		int space = ( int )command.find_first_of( " " );
		if ( space == -1 ) {
			break;
		}

		std::string word = command.substr( 0, space );
		_word.push_back( word );
		command = command.substr( space + 1, command.length( ) - space - 1 );
	}

	_word.push_back( command );
}
