#include "PaintTile.h"

PaintTile::PaintTile( ) {
	std::array< std::array< int, FieldProperty::FIELD_COL >, FieldProperty::FIELD_ROW >( ).swap( _color );

	for ( int i = 0; i < FieldProperty::FIELD_ROW; i++ ) {
		for ( int j = 0; j < FieldProperty::FIELD_COL; j++ ) {
			_color[ i ][ j ] = -1;
		}
	}
}

PaintTile::~PaintTile( ) {
}

void PaintTile::setTileColor( Vector pos, int player_num ) {
	_color[ pos.y ][ pos.x ] = player_num;
}

std::array< std::array< int, FieldProperty::FIELD_COL >, FieldProperty::FIELD_ROW > PaintTile::getTileColor( ) const {
	return _color;
}
