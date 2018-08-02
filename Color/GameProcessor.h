#pragma once
#include "smart_ptr.h"
#include "Vector.h"

PTR( GameProcessor );
PTR( Field );
PTR( PlayerUI );
PTR( Chara );
PTR( User );

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

public:
	FieldConstPtr getFieldPtr( ) const;
	PlayerUIConstPtr getUserUIPtr( ) const;
	PlayerUIConstPtr getEnemyUIPtr( ) const;
	CharaConstPtr getUserPtr( ) const;
	CharaConstPtr getEnemyPtr( ) const;

private:
	FieldPtr _field;
	PlayerUIPtr _user_ui;
	PlayerUIPtr _enemy_ui;
	UserPtr _user;
	CharaPtr _enemy;
};
