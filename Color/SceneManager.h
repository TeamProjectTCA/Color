#pragma once
#include "Base.h"
#include "Scene.h"
#include <string>

PTR( SceneManager );
PTR( Scene );
PTR( Title );
PTR( CharacterSelect );
PTR( Game );
PTR( Result );
PTR( ServerToClientDataUdp );


class SceneManager : public Base {
public:
	static SceneManagerPtr getTask( );
	static std::string getTag( );

public:
	SceneManager( ServerToClientDataUdpConstPtr recvdata );
	virtual ~SceneManager( );

public:
	void initialize( );
	void finalize( );
	void update( );

public:
	void setNextScene( SCENE next_scene );

private:
	void changeScene( );

private:
	SCENE _next_scene;
	ScenePtr _scene;
	ServerToClientDataUdpConstPtr _recvdata;
};

