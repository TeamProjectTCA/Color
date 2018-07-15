#pragma once
#include <array>
#include "Scene.h"
#include "smart_ptr.h"

PTR( SceneGame );
PTR( Keyboard );
PTR( Mouse );

const int ROW = 6;
const int COL = 6;

class SceneGame : public Scene {
public:
	SceneGame( );
	~SceneGame( );

public:
	void initialize( );
	void update( );

public:
	std::array< int, COL * ROW > getFieldData( ) const;

private:
	MousePtr _mouse;
	KeyboardPtr _keyboard;
	std::array< int, COL * ROW > _field_data;
};

