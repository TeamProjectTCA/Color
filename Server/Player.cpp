#include "Player.h"
#include "Sheet.h"
#include "ServerToClientDataUdp.h"
#include "BattleField.h"

const int SHEET_ROW = 2;
const int SHEET_TAG_PITCH = 100;
const int SHEET_VALUE_PITCH = 100;

Player::Player( const int PLAYER_IDX, BattleFieldConstPtr field ) :
_PLAYER_IDX( PLAYER_IDX ),
_field( field ),
_pos( ) {
	_pos = _field->getPlayerPos( _PLAYER_IDX );

	_sheet = SheetPtr( new Sheet( SHEET_ROW ) );
	_sheet->addCol( SHEET_TAG_PITCH );
	_sheet->addCol( SHEET_VALUE_PITCH );
	_sheet->addCol( SHEET_VALUE_PITCH );
	_sheet->write( 0, 0, "PLAYER" );
	_sheet->write( 1, 0, "X" );
	_sheet->write( 2, 0, "Y" );

	updateSheet( );
}

Player::~Player( ) {
}

void Player::update( ) {
	_pos = _field->getPlayerPos( _PLAYER_IDX );
	updateSheet( );
}

void Player::updateSheet( ) {
	_sheet->write( 0, 1, std::to_string( _PLAYER_IDX ) );
	_sheet->write( 1, 1, std::to_string( ( int )_pos.x ) );
	_sheet->write( 2, 1, std::to_string( ( int )_pos.y ) );
}

void Player::package( ServerToClientDataUdpPtr senddata ) {
	senddata->setPlayerPos( _PLAYER_IDX, _pos );
}

Vector Player::getPos( ) const {
	return _pos;
}

SheetPtr Player::getSheet( ) const {
	return _sheet;
}