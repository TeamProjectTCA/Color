#include "Turn.h"

Turn::Turn( ) :
_turn( TURN_MAX ) {
}

Turn::~Turn( ) {
}

void Turn::setTurn( int turn ) {
	_turn = turn;
}

int Turn::getTurn( ) const {
	return _turn;
}

void Turn::countTurn( ) {
	_turn--;
}