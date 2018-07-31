#include "NWOptionProcessor.h"
#include "Keyboard.h"

const int MAX_LENGTH = 15;
const char BACK[ ] = "BACK";

NWOptionProcessor::NWOptionProcessor( ) {
}

NWOptionProcessor::~NWOptionProcessor( ) {
}

void NWOptionProcessor::update( ) {
	write( );

}

void NWOptionProcessor::write( ) {
	KeyboardPtr keyboard = Keyboard::getTask( );

	std::string input = keyboard->getString( );
	if ( !keyboard->getKeyDown( input ) ) {
		return;
	}

	if ( input == BACK && !_new_ip.empty( ) ) {
		_new_ip.pop_back( );
	}

	if ( _new_ip.length( ) >= MAX_LENGTH ) {
		return;
	}

	int ascii = input[ 0 ];
	if ( ( ascii < '0' || '9' < ascii ) && ascii != '.' ) {
		return;
	}

	_new_ip.push_back( input[ 0 ] );
}