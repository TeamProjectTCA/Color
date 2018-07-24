#pragma once
#include "smart_ptr.h"
#include <string>
#include <vector>

PTR( Sheet );

class Sheet {
public:
	Sheet( const int ROW_NUM, bool draw_horizontal = true );
	virtual ~Sheet( );

public:
	void setPos( float x, float y );
	void addCol( int pitch );
	void write( int col, int row, std::string message );

public:
	float getWidth( ) const;
	float getHeight( ) const;
	std::string getValue( int col, int row ) const;

public:
	void draw( ) const;

private:
	void drawFrame( ) const;
	void drawValue( ) const;

private:
	bool _draw_horizontal;
	int _row;
	int _col;

	float _x;
	float _y;
	float _width;
	float _height;

	std::vector< int > _col_pitch;
	std::vector< std::vector< std::string > > _value;
};

