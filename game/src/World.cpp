#include "Game/World.h"

World::World(TileIds& tile_ids)
    : map(24, 24, tile_ids)
{
}

const TileMap& World::get_tilemap() const
{
    return this->map;
}
