#pragma once

#include "Core/Types.h"

class Renderer;
class World;
class TileRegistry;

class RenderSystem
{
public:
    RenderSystem(const World& world);

    void render(Renderer& renderer, const TileRegistry& tile_reg) const;

    void render_entities(Renderer& renderer) const;
    void render_tilemap(Renderer& renderer, const TileRegistry& tile_reg) const;

private:
    const World& world;

    ComponentMask required;
};
