#pragma once
#include "Base.h"
#include <string>

PTR( SceneManager );
PTR( Scene );
PTR( SceneTitle );
PTR( SceneCharacterSelect );
PTR( SceneGame );
PTR( SceneResult );


class SceneManager : public Base {
public:
	static SceneManagerPtr getTask( );
	static std::string getTag( );

public:
	SceneManager( );
	virtual ~SceneManager( );

public:
	void initialize( );
	void finalize( );
	void update( );

private:
	void changeScene( );

private:
	ScenePtr _scene;
	ScenePtr _view_scene;
	SceneTitlePtr _scene_title;
	SceneCharacterSelectPtr _scene_character_select;
	SceneGamePtr _scene_game;
	SceneResultPtr _scene_result;
};

