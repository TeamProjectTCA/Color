#pragma once
#include "smart_ptr.h"
#include "Vector.h"
#include <array>

PTR( ProcessorForServer );
PTR( ServerToClientDataUdp );
PTR( ServerToClientDataTcp );
PTR( ClientToServerData );
PTR( Log );
PTR( Command );
PTR( Player );

class ProcessorForServer {
public:
	ProcessorForServer( ClientToServerDataConstPtr recv_data,  ServerToClientDataUdpPtr senddata_udp, ServerToClientDataTcpPtr senddata_tcp, LogPtr log, CommandPtr command );
	virtual ~ProcessorForServer( );

public:
	void update( );

private:
	void packageData( );
	void playerMove( );
	
public:
	int getTurn( ) const;
	const int getTURNMAX( ) const;
	bool isGameOver( ) const;
	PlayerConstPtr getPlayer0Ptr( ) const;
	PlayerConstPtr getPlayer1Ptr( ) const;

private:
	int _turn;
	bool sended_tcp;
	std::array< Vector, 2 > _player_init_pos;

	ServerToClientDataUdpPtr _senddata_udp;
	ServerToClientDataTcpPtr _senddata_tcp;
	ClientToServerDataConstPtr _recv_data;
	CommandPtr _command;
	std::array< PlayerPtr, 2 > _player;
};

