#include "PaintTile.h"

const int TILE_STATE_NONE = 0;

PaintTile::PaintTile( ) {
	std::array< std::array< int, FieldProperty::FIELD_COL >, FieldProperty::FIELD_ROW >( ).swap( _color );

	for ( int i = 0; i < FieldProperty::FIELD_ROW; i++ ) {
		for ( int j = 0; j < FieldProperty::FIELD_COL; j++ ) {
			_color[ i ][ j ] = TILE_STATE_NONE;
		}
	}
}

PaintTile::~PaintTile( ) {
}

void PaintTile::setTileColor( Vector pos, int player_num ) {
	_color[ ( int ) pos.y ][ ( int ) pos.x ] = player_num + 1;
}

int PaintTile::getPaintCount( int player_num ) const {
	int count = 0;
	for ( int i = 0; i < FieldProperty::FIELD_ROW; i++ ) {
		for ( int j = 0; j < FieldProperty::FIELD_COL; j++ ) {
			if ( _color[ i ][ j ] == player_num + 1 ) {
				count++;
			}
		}
	}
	return count;
}

std::array< std::array< int, FieldProperty::FIELD_COL >, FieldProperty::FIELD_ROW > PaintTile::getTileColor( ) const {
	return _color;
}