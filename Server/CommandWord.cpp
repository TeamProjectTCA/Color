#include "CommandWord.h"

const char ERROR[ ] = "<<<ERROR>>>";

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

int CommandWord::getTokenCount( ) const {
	return ( int )_word.size( );
}

std::string CommandWord::getTokenString( int idx ) const {
	return _word[ idx ];
}

int CommandWord::getTokenValue( int idx ) const {
	return std::atoi( _word[ idx ].c_str( ) );
}

std::string CommandWord::makeUnknownError( ) const {
	std::string error;
	error = error + ERROR + " [";

	for ( std::string word : _word ) {
		error += " ";
		error += word;
	}

	error += " ] is Unknown Command";
	return error;
}

std::string CommandWord::makeError( int error_idx, std::string cause ) const {
	if ( error_idx >= _word.size( ) ) {
		std::string idx_over;
		idx_over = idx_over + ERROR + " error_idx is over range";
		return idx_over;
	}

	std::string error = ERROR;
	for ( int i = 0; i < error_idx; i++ ) {
		error += " ";
		error += getTokenString( i );
	}

	error += cause;
	return error;
}