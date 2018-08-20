#pragma once
#include "smart_ptr.h"
#include "Vector.h"
#include "FieldProperty.h"

PTR( GameProcessor );
PTR( Viewer );
PTR( Field );
PTR( PlayerUI );
PTR( Chara );
PTR( User );
PTR( Move );
PTR( GlobalUI );
PTR( PaintCount );

class GameProcessor {
public:
	GameProcessor( ViewerPtr viewer );
	virtual ~GameProcessor( );

public:
	void update( );

public:
	void setUserFieldIdx( Vector pos );
	void setEnemyFieldIdx( Vector pos );
	void setUserPaintCount( int paint_count );
	void setEnemyPaintCount( int paint_count );
	void setPlayerIdx( int player_idx );
	void setTurn( int turn );
	void setGameOver( bool gameover );
	void setTileState( int x, int y, FieldProperty::TILE_STATE state );

public:
	FieldConstPtr getFieldPtr( ) const;
	GlobalUIPtr getGlobalUIPtr( ) const;
	PlayerUIConstPtr getUserUIPtr( ) const;
	PlayerUIConstPtr getEnemyUIPtr( ) const;
	CharaConstPtr getUserPtr( ) const;
	CharaConstPtr getEnemyPtr( ) const;

private:
	bool _gameover;

	FieldPtr _field;
	GlobalUIPtr _global_ui;
	PlayerUIPtr _user_ui;
	PlayerUIPtr _enemy_ui;
	UserPtr _user;
	CharaPtr _enemy;
	MovePtr _move;
	PaintCountPtr _paint_count;
};
