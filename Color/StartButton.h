#pragma once
#include "smart_ptr.h"
#include "Vector.h"

PTR( StartButton );

class StartButton {
public:
	enum BUTTON_STATE {
		BUTTON_STATE_NORMAL,
		BUTTON_STATE_PUSH,
		BUTTON_STATE_MAX
	};
public:
	StartButton( );
	virtual ~StartButton( );

public:
	void update( );

private:
	void setCollider( float lx, float ly, float rx, float ry );
	void click( Vector mouse );

public:
	Vector getButtonPos( ) const;
	BUTTON_STATE getButtonState( ) const;

private:
	// “–‚½‚è”»’è
	float _lx;
	float _ly;
	float _rx;
	float _ry;

	BUTTON_STATE _state;
	Vector _button_pos;
};

