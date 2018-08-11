#pragma once
#include "smart_ptr.h"
#include "Vector.h"

PTR( GameProcessor );
PTR( Field );
PTR( PlayerUI );
PTR( Chara );
PTR( User );
PTR( Move );

class GameProcessor {
public:
	GameProcessor( );
	virtual ~GameProcessor( );

public:
	void update( );

public:
	void setUserPos( Vector pos );
	void setEnemyPos( Vector pos );
	void setPlayerNum( int player_num );
	void setTurn( int turn );
	void setGameOver( bool gameover );

public:
	int getTurn( ) const;
	Vector getClickMas( ) const;
	FieldConstPtr getFieldPtr( ) const;
	PlayerUIConstPtr getUserUIPtr( ) const;
	PlayerUIConstPtr getEnemyUIPtr( ) const;
	CharaConstPtr getUserPtr( ) const;
	CharaConstPtr getEnemyPtr( ) const;

private:
	int _turn;
	bool _gameover;

	FieldPtr _field;
	PlayerUIPtr _user_ui;
	PlayerUIPtr _enemy_ui;
	UserPtr _user;
	CharaPtr _enemy;
	MovePtr _move;
};
