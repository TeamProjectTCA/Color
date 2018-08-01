#pragma once
#include "smart_ptr.h"

PTR( GameProcessor );
PTR( Field );
PTR( PlayerUI );

class GameProcessor {
public:
	GameProcessor( );
	virtual ~GameProcessor( );

public:
	void update( );

public:
	FieldConstPtr getFieldPtr( ) const;
	PlayerUIConstPtr getPlayer1UIPtr( ) const;
	PlayerUIConstPtr getPlayer2UIPtr( ) const;

private:
	FieldPtr _field;
	PlayerUIPtr _player1_ui;
	PlayerUIPtr _player2_ui;
};
