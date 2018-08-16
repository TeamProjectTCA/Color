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
	ImageConstPtr base_tile = drawer->getImage( WHITE_TILE );
	ImageConstPtr red_tile  = drawer->getImage( RED_TILE );
	ImageConstPtr blue_tile = drawer->getImage( BLUE_TILE );
	_base_tile = base_tile->getHandle( );
	_red_tile  = red_tile->getHandle( );
	_blue_tile = blue_tile->getHandle( );
}

Field::~Field( ) {
}

void Field::draw( ) const {
	DrawerPtr drawer = Drawer::getTask( );

	for ( int i = 0; i < FieldProperty::FIELD_ROW; i++ ) {
		for ( int j = 0; j < FieldProperty::FIELD_COL; j++ ) {
			ImagePtr tile( new Image( ) );
			switch ( _tile[ i ][ j ]->getState( ) ) {
			case FieldProperty::TILE_STATE_NONE :
				tile->setHandle( _base_tile );
				break;
			case FieldProperty::TILE_STATE_PLAYER0:
				tile->setHandle( _red_tile );
				break;
			case FieldProperty::TILE_STATE_PLAYER1:
				tile->setHandle( _blue_tile );
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

void Field::setTileState( int x, int y, FieldProperty::TILE_STATE state ) {
	_tile[ y ][ x ]->setState( state );
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