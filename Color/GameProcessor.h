#pragma once
#include "smart_ptr.h"
#include "Vector.h"

PTR( GameProcessor );
PTR( Field );
PTR( PlayerUI );
PTR( Chara );

class GameProcessor {
public:
	GameProcessor( );
	virtual ~GameProcessor( );

public:
	void update( );

public:
	void setPlayer0Pos( Vector pos );
	void setPlayer1Pos( Vector pos );

public:
	FieldConstPtr getFieldPtr( ) const;
	PlayerUIConstPtr getPlayer0UIPtr( ) const;
	PlayerUIConstPtr getPlayer1UIPtr( ) const;
	CharaConstPtr getPlayer0Ptr( ) const;
	CharaConstPtr getPlayer1Ptr( ) const;

private:
	FieldPtr _field;
	PlayerUIPtr _player0_ui;
	PlayerUIPtr _player1_ui;
	CharaPtr _player0;
	CharaPtr _player1;
};
