#include "Game/TileRegistry.h"

const TileDefinition& TileRegistry::operator[](size_t idx) const
{
    return this->definitions[idx];
}

TileDefinition& TileRegistry::operator[](size_t idx)
{
    return this->definitions[idx];
}

size_t TileRegistry::size() const
{
    return this->definitions.size();
}

TileId TileRegistry::register_tile(TileDefinition&& definition)
{
    this->definitions.push_back(std::move(definition));

    return static_cast<TileId>(this->definitions.size() - 1);
}

TileIds register_tiles(TileRegistry& registry)
{
    TileIds ids;
    ids.empty = registry.register_tile({
        .is_walkable = false,
        .blocks_sight = false,
        .movement_cost  = 0,
        .color = {.r = 0.8f, .g = 0.0f, .b = 0.8f}
    });

    ids.floor = registry.register_tile({
        .is_walkable = true,
        .blocks_sight = false,
        .movement_cost  = 1,
        .color = {.r = 0.8f, .g = 0.8f, .b = 0.8f}
    });

    return ids;
}
