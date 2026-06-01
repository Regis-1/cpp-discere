#pragma once

#include "Engine/EntityManager.h"
#include "Engine/ComponentManager.hpp"

#include "Game/TileMap.h"
#include "Game/TileRegistry.h"
#include "Game/RenderSystem.h"

class TileIds;
class Renderer;
class World;

class World
{
public:
    World(TileIds& tile_ids);

    void render(Renderer &renderer, TileRegistry &tile_registry);

    Entity new_entity();
    void destroy_entity(Entity entity);

    template <typename T>
    void add_component(Entity entity, const T& component);

    template <typename T>
    void remove_component(Entity entity);

    template <typename... T>
    bool has_component(Entity entity) const;

    template <typename T>
    const T& get_component(Entity entity) const;

private:
    TileMap map;

    EntityManager entity_mngr;
    ComponentManager component_mngr;

    RenderSystem render_system;

    Entity villagers[2];
};

template <typename T>
void World::add_component(Entity entity, const T& component)
{
    this->component_mngr.add_component<T>(entity, component);

    ComponentTypeId id = this->component_mngr.get_component_type_id<T>();

    this->entity_mngr.set_component(entity, id);
}

template <typename T>
void World::remove_component(Entity entity)
{
    this->component_mngr.remove_component<T>(entity);

    ComponentTypeId id = this->component_mngr.get_component_type_id<T>();

    this->entity_mngr.reset_component(entity, id);
}

template <typename... Ts>
bool World::has_component(Entity entity) const
{
    ComponentMask required;
    (required.set(this->component_mngr.get_component_type_id<Ts>()), ...);

    return (this->entity_mngr.get_mask(entity) & required) == required;
}

template <typename T>
const T& World::get_component(Entity entity) const
{
    return this->component_mngr.get_component<T>(entity);
}
