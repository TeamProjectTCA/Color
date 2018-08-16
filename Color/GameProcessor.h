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
PTR( ShowTurn );
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
	void setPlayerNum( int player_num );
	void setTurn( int turn );
	void setGameOver( bool gameover );
	void setColor( std::array< std::array< int, FieldProperty::FIELD_COL >, FieldProperty::FIELD_ROW > color );
	void setPaintCount( int player_num, int paint_count );

public:
	FieldConstPtr getFieldPtr( ) const;
	PlayerUIConstPtr getUserUIPtr( ) const;
	PlayerUIConstPtr getEnemyUIPtr( ) const;
	CharaConstPtr getUserPtr( ) const;
	CharaConstPtr getEnemyPtr( ) const;
	ShowTurnPtr getShowTurnPtr( ) const;
	PaintCountPtr getPaintCountPtr( ) const;

private:
	bool _gameover;

	FieldPtr _field;
	PlayerUIPtr _user_ui;
	PlayerUIPtr _enemy_ui;
	UserPtr _user;
	CharaPtr _enemy;
	MovePtr _move;
	ShowTurnPtr _turn;
	PaintCountPtr _paint_count;
};
