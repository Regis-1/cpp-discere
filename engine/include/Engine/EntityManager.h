#pragma once

#include <vector>
#include <array>

#include <Core/Types.h>

class EntityManager
{
public:
    EntityManager();

    [[nodiscard]]
    Entity new_entity();

    void destroy_entity(Entity entity);

    const ComponentMask& get_mask(Entity entity) const;

    void set_component(Entity entity, ComponentTypeId component_id);
    void reset_component(Entity entity, ComponentTypeId component_id);

    const Entity get_next_id() const;

private:
    Entity next_id = 0;

    std::array<ComponentMask, MAX_ENTITIES> component_masks;

    std::vector<Entity> free_ids;
};
