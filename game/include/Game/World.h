#pragma once

#include "Game/TileMap.h"
#include "Game/TileRegistry.h"

class TileIds;
class Renderer;

class World
{
public:
    World(TileIds& tile_ids);

    const TileMap& get_tilemap() const;

private:
    TileMap map;
};
