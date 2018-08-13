#include "Turn.h"

const int TURN_MAX = 40 * 2;

Turn::Turn( ) :
_turn( TURN_MAX ){
}


Turn::~Turn( ) {
}

void Turn::setTurn( int turn ) {
	_turn = turn;
}

int Turn::getTurn( ) const {
	return _turn;
}

const int Turn::getTURNMAX( ) const {
	return TURN_MAX;
}

void Turn::countTurn( ) {
	_turn--;
}