#include "Game/TileMap.h"
#include "Game/TileRegistry.h"

#include <cassert>
#include <iostream>

TileMap::TileMap(int width, int height, TileIds tile_ids)
    : width(width), height(height), tile_ids(tile_ids)
{
    assert(this->width > 0 && this->height > 0);

    this->ground.assign(width * height, this->tile_ids.floor);

    set_ground(2, 2, this->tile_ids.empty);
    set_ground(2, 3, this->tile_ids.empty);
}

const int TileMap::tile_count() const
{
    return this->width * this->height;
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

void TileMap::draw(Renderer &renderer, const TileRegistry &tile_registry) const
{
    constexpr float tile_size = 32.0f;
    constexpr float tile_offset = 4.0f;

    float x, y;
    for (int i = 0; i < this->ground.size(); ++i)
    {
        const Color &c = tile_registry[this->ground[i]].color;
        renderer.set_draw_color(c.r, c.g, c.b);

        x = static_cast<float>(i % this->width) * (tile_size + tile_offset);
        y = static_cast<float>(i / this->width) * (tile_size + tile_offset);

        renderer.draw_rectangle(x, y, tile_size, tile_size);
    }
}
