#pragma once
#include "Base.h"
#include "Scene.h"
#include <string>

PTR( SceneManager );
PTR( Scene );
PTR( ServerToClientDataUdp );
PTR( ServerToClientDataTcp );

class SceneManager : public Base {
public:
	static SceneManagerPtr getTask( );
	static std::string getTag( ) { return "SCENE_MANAGER"; }

public:
	SceneManager( ServerToClientDataTcpConstPtr recvdata_tcp, ServerToClientDataUdpConstPtr recvdata_udp );
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
	ScenePtr _scene;
	ServerToClientDataUdpConstPtr _recvdata_udp;
	ServerToClientDataTcpConstPtr _recvdata_tcp;
	SCENE _next_scene;
	SCENE _now_scene;
};

