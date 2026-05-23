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

    [[nodiscard]]
    const int tile_count() const;

    [[nodiscard]] TileId get_ground(int x, int y) const;

    void set_ground(int x, int y, TileId id);

    [[nodiscard]] size_t to_index(int x, int y) const;

    void draw(Renderer &renderer, const TileRegistry &tile_registry) const;

private:
    int width;
    int height;

    TileIds &tile_ids;

    std::vector<TileId> ground;
};
