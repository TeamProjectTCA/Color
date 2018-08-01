#include "Field.h"
#include "Tile.h"

const int TILE_SIZE = 96;

Field::Field( const Vector ORIGIN_POS ) :
Area( ORIGIN_POS ){
	std::array< std::array< TilePtr, FieldProperty::FIELD_COL >, FieldProperty::FIELD_ROW >( ).swap( _tile );
	const int START_POS_X = TILE_SIZE / 4 + TILE_SIZE / 2;
	const int START_POS_Y = TILE_SIZE / 2 + TILE_SIZE / 2;

	for ( int i = 0; i < FieldProperty::FIELD_ROW; i++ ) {
		for ( int j = 0; j < FieldProperty::FIELD_COL; j++ ) {
			TilePtr tile( new Tile( Vector( START_POS_X + j * TILE_SIZE, START_POS_Y + i * TILE_SIZE ) ) );
			_tile[ i ][ j ] = tile;
		}
	}
}

Field::~Field( ) {
}

Vector Field::getCenterPos( ) const {
	Vector origin = getOrigin( );

	return origin;
}

Vector Field::getTilePos( int x, int y ) const {
	Vector origin = getOrigin( );
	Vector tile = _tile[ y ][ x ]->getPos( );

	return tile + origin;
}