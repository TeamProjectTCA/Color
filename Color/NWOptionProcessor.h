#pragma once
#include "smart_ptr.h"
#include "Vector.h"
#include <string>

PTR( NWOptionProcessor );

class NWOptionProcessor {
public:
	NWOptionProcessor( );
	virtual ~NWOptionProcessor( );

public:
	void update( );

private:
	void write( );

public:
	std::string getNowIP( ) const;
	std::string getNewIP( ) const;
	Vector getNowIPPos( ) const;
	Vector getNewIPPos( ) const;

private:
	std::string _now_ip;
	std::string _new_ip;

	Vector _now_ip_pos;
	Vector _new_ip_pos;
};

