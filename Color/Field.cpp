#include "Field.h"
#include "Tile.h"

#include "Image.h"
#include "Drawer.h"

const char WHITE_TILE[ ] = "Field/WhiteTile.png";
const char RED_TILE[ ] = "Field/RedTile.png";
const char BLUE_TILE[ ] = "Field/BlueTile.png";

const int TILE_SIZE = 96;

Field::Field( const Vector ORIGIN_POS ) :
Area( ORIGIN_POS ) {
	std::array< std::array< TilePtr, FieldProperty::FIELD_COL >, FieldProperty::FIELD_ROW >( ).swap( _tile );
	const int START_POS_X = TILE_SIZE / 4 + TILE_SIZE / 2;
	const int START_POS_Y = TILE_SIZE / 2 + TILE_SIZE / 2;

	for ( int i = 0; i < FieldProperty::FIELD_ROW; i++ ) {
		for ( int j = 0; j < FieldProperty::FIELD_COL; j++ ) {
			TilePtr tile( new Tile( Vector( START_POS_X + j * TILE_SIZE, START_POS_Y + i * TILE_SIZE ) ) );
			_tile[ i ][ j ] = tile;
		}
	}


	DrawerPtr drawer = Drawer::getTask( );
	_base_tile = drawer->getImage( WHITE_TILE );
	_red_tile = drawer->getImage( RED_TILE );
	_blue_tile = drawer->getImage( BLUE_TILE );
}

Field::~Field( ) {
}

void Field::draw( ) const {
	DrawerPtr drawer = Drawer::getTask( );

	for ( int i = 0; i < FieldProperty::FIELD_ROW; i++ ) {
		for ( int j = 0; j < FieldProperty::FIELD_COL; j++ ) {
			ImagePtr tile( new Image( ) );
			switch ( ( Tile::TILE_STATE )_color[ i ][ j ] ) {
			case Tile::TILE_STATE_NONE :
				tile->setHandle( _base_tile->getHandle( ) );
				break;
			case Tile::TILE_STATE_PLAYER0:
				tile->setHandle( _red_tile->getHandle( ) );
				break;
			case Tile::TILE_STATE_PLAYER1:
				tile->setHandle( _blue_tile->getHandle( ) );
				break;
			default:
				break;
			}
			tile->setCentral( true );

			Vector pos = getTilePos( j, i );
			tile->setPos( ( int ) pos.x, ( int ) pos.y );
			tile->draw( );
		}
	}
}

void Field::setColor( std::array< std::array< int, FieldProperty::FIELD_COL >, FieldProperty::FIELD_ROW > color ) {
	_color = color;
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

const int Field::getTileSize( ) const {
	return TILE_SIZE;
}