#pragma once

#include <cstddef>
#include <vector>

#include "Core/Types.h"
#include "Engine/Renderer.h"

class TileRegistry;
class TileIds;

class TileMap
{
public:
    TileMap(int width, int height, TileIds ids);

    const size_t size() const;

    TileId get_ground(int idx) const;
    TileId get_ground(int x, int y) const;

    void set_ground(int x, int y, TileId id);

    size_t to_index(int x, int y) const;

    const int get_width() const;
    const int get_height() const;

private:
    int width;
    int height;

    TileIds &tile_ids;

    std::vector<TileId> ground;
};
