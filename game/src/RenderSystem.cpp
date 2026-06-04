#include "Game/RenderSystem.h"
#include "Game/Components.h"
#include "Game/World.h"
#include "Game/TileRegistry.h"

#include "Engine/Renderer.h"

RenderSystem::RenderSystem(const World& world)
    : world(world)
{
    const ComponentManager& cm = world.get_component_manager();

    this->required.set(cm.get_component_type_id<CTransform>());
    this->required.set(cm.get_component_type_id<CColor>());
}

void RenderSystem::render(Renderer& renderer, const TileRegistry& tile_reg) const
{
    render_tilemap(renderer, tile_reg);
    render_entities(renderer);
}

void RenderSystem::render_entities(Renderer& renderer) const
{
    const EntityManager& em = this->world.get_entity_manager();
    const ComponentManager& cm = world.get_component_manager();

    for (Entity e = 0; e < em.get_next_id(); ++e)
    {
        if ((em.get_mask(e) & required) != required)
        {
            continue;
        }

        auto& transform = cm.get_component<CTransform>(e);
        auto& color = cm.get_component<CColor>(e);

        renderer.set_draw_color(color.r, color.g, color.b);
        renderer.draw_rectangle(transform.x, transform.y, 16, 16);
    }
}

void RenderSystem::render_tilemap(Renderer& renderer, const TileRegistry& tile_reg) const
{
    constexpr float tile_size = 32.0f;
    constexpr float tile_offset = 4.0f;

    const TileMap& map = this->world.get_tilemap();
    const int width = map.get_width();
    const int height = map.get_height();

    float x, y;
    for (int i = 0; i < map.size(); ++i)
    {
        const Color& c = tile_reg[map.get_ground(i)].color;
        renderer.set_draw_color(c.r, c.g, c.b);

        x = static_cast<float>(i % width) * (tile_size + tile_offset);
        y = static_cast<float>(i / width) * (tile_size + tile_offset);

        renderer.draw_rectangle(x, y, tile_size, tile_size);
    }
}
