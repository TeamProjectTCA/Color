#include "ViewPlayer.h"
#include "Player.h"
#include "Sheet.h"

const int SHEET_ROW = 2;
const int SHEET_TAG_PITCH = 100;
const int SHEET_VALUE_PITCH = 100;

ViewPlayer::ViewPlayer( PlayerConstPtr player ) :
_player( player ) {
	_sheet = SheetPtr( new Sheet( SHEET_ROW ) );
	_sheet->addCol( SHEET_TAG_PITCH );
	_sheet->addCol( SHEET_VALUE_PITCH );
	_sheet->addCol( SHEET_VALUE_PITCH );
	_sheet->write( 0, 0, "PLAYER" );
	_sheet->write( 1, 0, "X" );
	_sheet->write( 2, 0, "Y" );
}

ViewPlayer::~ViewPlayer( ) {
}

void ViewPlayer::initialize( ) {
	updateSheet( );
}

void ViewPlayer::updateSheet( ) {
	const int PLAYER_NUM = _player->getPlayerNum( );
	Vector pos = _player->getPos( );

	_sheet->write( 0, 1, std::to_string( PLAYER_NUM ) );
	_sheet->write( 1, 1, std::to_string( ( int )pos.x ) );
	_sheet->write( 2, 1, std::to_string( ( int )pos.y ) );
}

SheetPtr ViewPlayer::getSheet( ) const {
	return _sheet;
}