#pragma once

#include <cstddef>
#include <vector>

#include "Core/Types.h"

struct Color
{
    float r;
    float g;
    float b;
};

struct TileDefinition
{
    bool is_walkable;
    bool blocks_sight;
    int  movement_cost;

    Color color;
};

struct TileIds
{
    TileId empty;
    TileId floor;
};

class TileRegistry
{
public:
    const TileDefinition& operator[](size_t idx) const;
    TileDefinition& operator[](size_t idx);

    size_t size() const;

    TileId register_tile(TileDefinition&& definition);

private:
    std::vector<TileDefinition> definitions;
};

TileIds register_tiles(TileRegistry& registry);
