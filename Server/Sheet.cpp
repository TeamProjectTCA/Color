#include "Sheet.h"
#include "Drawer.h"

const unsigned int SHOW_COLOR = 0xffffff;
const float ROW_PITCH = 25.0f;

Sheet::Sheet( const int ROW_NUM ) :
_row( ROW_NUM ),
_col( 0 ),
_x( 0 ),
_y( 0 ),
_width( 0 ),
_height( _row * ROW_PITCH ) {
	for ( int i = 0; i < _row; i++ ) {
		_value.push_back( std::vector< std::string >( ) );
	}
}

Sheet::~Sheet( ) {
}

void Sheet::setPos( float x, float y ) {
	_x = x;
	_y = y;
}

void Sheet::addCol( int pitch ) {
	_col_pitch.push_back( pitch );

	_col++;
	_width += pitch;

	for ( int i = 0; i < _row; i++ ) {
		_value[ i ].push_back( "" );
	}
}

void Sheet::write( int col, int row, std::string message ) {
	_value[ row ][ col ] = message;
}

float Sheet::getWidth( ) const {
	return _width;
}

float Sheet::getHeight( ) const {
	return _height;
}

void Sheet::draw( ) const {
	drawFrame( );
	drawValue( );
}

void Sheet::drawValue( ) const {
	DrawerPtr drawer = Drawer::getTask( );

	const int LEFT_PITCH = 5;
	const int UP_PITCH = 5;

	for ( int i = 0; i < _row; i++ ) {
		float x = _x;
		for ( int j = 0; j < _col; j++ ) {
			if ( j > 0 ) {
				x += _col_pitch[ j - 1 ];
			}

			float y = _y + i * ROW_PITCH;

			drawer->drawFormatString( x + LEFT_PITCH, y + UP_PITCH, SHOW_COLOR, _value[ i ][ j ].c_str( ) );
		}
	}
}

void Sheet::drawFrame( ) const {
	DrawerPtr drawer = Drawer::getTask( );

	// â°ê¸
	const float LEFT       = _x;
	const float RIGHT      = _x + _width;
	const int X_LINE_NUM = _row + 1;

	for ( int i = 0; i < X_LINE_NUM; i++ ) {
		float sy = _y + i * ROW_PITCH;
		float ey = sy;
		drawer->drawLine( LEFT, sy, RIGHT, ey, SHOW_COLOR );
	}

	// ècê¸
	const float TOP        = _y;
	const float BOTTOM     = _y + _height;
	const int Y_LINE_NUM = _col + 1;

	float sx = _x;
	for ( int i = 0; i < Y_LINE_NUM; i++ ) {
		if ( i > 0 ) {
			sx += _col_pitch[ i - 1 ];
		}

		float ex = sx;
		drawer->drawLine( sx, TOP, ex, BOTTOM, SHOW_COLOR );
	}
}