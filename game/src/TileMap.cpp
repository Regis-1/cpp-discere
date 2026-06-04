#include "Game/TileMap.h"
#include "Game/TileRegistry.h"

#include <cassert>

TileMap::TileMap(int width, int height, TileIds tile_ids)
    : width(width), height(height), tile_ids(tile_ids)
{
    assert(this->width > 0 && this->height > 0);

    this->ground.assign(width * height, this->tile_ids.floor);

    set_ground(2, 2, this->tile_ids.empty);
    set_ground(2, 3, this->tile_ids.empty);
}

const size_t TileMap::size() const
{
    return this->ground.size();
}

TileId TileMap::get_ground(int idx) const
{
    assert(idx < this->ground.size());

    return this->ground[idx];
}

TileId TileMap::get_ground(int x, int y) const
{
    assert(x >= 0 && x < this->width);
    assert(y >= 0 && y < this->height);

    return this->ground[to_index(x, y)];
}

void TileMap::set_ground(int x, int y, TileId id)
{
    assert(x >= 0 && x < this->width);
    assert(y >= 0 && y < this->height);

    this->ground[to_index(x, y)] = id;
}

size_t TileMap::to_index(int x, int y) const
{
    return static_cast<size_t>(y * this->width + x);
}

const int TileMap::get_width() const
{
    return this->width;
}

const int TileMap::get_height() const
{
    return this->height;
}
