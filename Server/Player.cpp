#include "Player.h"
#include "Sheet.h"
#include "ServerToClientDataUdp.h"
#include "BattleField.h"
#include "FieldProperty.h"

const int SHEET_ROW = 2;
const int SHEET_TAG_PITCH = 100;
const int SHEET_VALUE_PITCH = 100;

Player::Player( const int PLAYER_IDX, BattleFieldConstPtr field ) :
_PLAYER_IDX( PLAYER_IDX ),
_field( field ),
_pos( ),
_respawn( false ) {
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
	_respawn = false;

	if ( isMove( ) ) {
		move( );
	}

	updateSheet( );
}

void Player::updateSheet( ) {
	_sheet->write( 0, 1, std::to_string( _PLAYER_IDX ) );
	_sheet->write( 1, 1, std::to_string( ( int )_pos.x ) );
	_sheet->write( 2, 1, std::to_string( ( int )_pos.y ) );
}

void Player::move( ) {
	respawn( );

	_pos = _field->getPlayerPos( _PLAYER_IDX );
}

void Player::respawn( ) {
	Vector pos = _field->getPlayerPos( _PLAYER_IDX );
	int after_x = ( int )pos.x;
	int after_y = ( int )pos.y;
	Vector init_pos = FieldProperty::getPlayerInitPos( _PLAYER_IDX );
	int init_x = ( int )init_pos.x;
	int init_y = ( int )init_pos.y;

	if ( after_x != init_x || after_y != init_y ) {
		return;
	}

	Vector click_idx = _field->getClickIdx( );
	int click_x = ( int )click_idx.x;
	int click_y = ( int )click_idx.y;

	if ( click_x == init_x && click_y == init_y ) {
		return;
	}

	_respawn = true;
}

void Player::package( ServerToClientDataUdpPtr senddata ) {
	senddata->setPlayerPos( _PLAYER_IDX, _pos );
}

bool Player::isMove( ) const {
	#if debug != 0
	if ( _PLAYER_IDX == 1 ) {
		return 1;
	}
	#endif

	return ( _pos != _field->getPlayerPos( _PLAYER_IDX ) );
}

bool Player::isRespawn( ) const {
	return _respawn;
}

Vector Player::getPos( ) const {
	return _pos;
}

SheetPtr Player::getSheet( ) const {
	return _sheet;
}