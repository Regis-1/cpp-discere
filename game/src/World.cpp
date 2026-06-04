#include "Game/World.h"
#include "Game/Components.h"
#include "Engine/Input.h"

#include <iostream>

World::World(TileIds& tile_ids)
    : map(24, 24, tile_ids),
      render_system(this->component_mngr)
{
    this->villagers[0] = new_entity();
    this->villagers[1] = new_entity();

    CTransform pos { .x = 8, .y = 8 };
    CColor color { .r = 0.0f, .g = 0.6f, .b = 0.4f };
    add_component<CTransform>(this->villagers[0], pos);
    add_component<CColor>(this->villagers[0], color);

    pos = { .x = 40, .y = 8 };
    color = { .r = 1.0f, .g = 0.0f, .b = 0.2f };
    add_component<CTransform>(this->villagers[1], pos);
    add_component<CColor>(this->villagers[1], color);
}

World::~World()
{
    destroy_entity(this->villagers[0]);
    destroy_entity(this->villagers[1]);
}

void World::update(const Input &input)
{
    if (input.is_pressed(Action::Pause))
    {
        std::cout << "Action Pause was pressed." << std::endl;
        auto &transform_comp = this->component_mngr.get_component<CTransform>(this->villagers[0]);
        transform_comp.y += 8;
    }
}

void World::render(Renderer &renderer, TileRegistry &tile_registry)
{
    this->map.draw(renderer, tile_registry);

    this->render_system.render(renderer, this->entity_mngr, this->component_mngr);
}

Entity World::new_entity()
{
    return this->entity_mngr.new_entity();
}

void World::destroy_entity(Entity entity)
{
    auto &mask = this->entity_mngr.get_mask(entity);

    this->component_mngr.remove_all(entity, mask);

    this->entity_mngr.destroy_entity(entity);
}
