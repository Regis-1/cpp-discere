#include "Engine/EntityManager.h"

#include <iostream>

EntityManager::EntityManager()
{
    this->free_ids.reserve(MAX_ENTITIES);
}

Entity EntityManager::new_entity()
{
    Entity id;

    if (!this->free_ids.empty())
    {
        std::cout << "recycled entity" << std::endl;
        id = this->free_ids.back();
        this->free_ids.pop_back();
    }
    else
    {
        std::cout << "new entity" << std::endl;
        id = this->next_id++;
    }

    this->component_masks[id].reset();

    return id;
}

void EntityManager::destroy_entity(Entity entity)
{
    this->component_masks[entity].reset();
    this->free_ids.push_back(entity);
}

const ComponentMask& EntityManager::get_mask(Entity entity) const
{
    return this->component_masks[entity];
}

void EntityManager::set_component(Entity entity, ComponentTypeId component_id)
{
    this->component_masks[entity].set(component_id);
}

void EntityManager::reset_component(Entity entity, ComponentTypeId component_id)
{
    this->component_masks[entity].reset(component_id);
}

const Entity EntityManager::get_next_id() const
{
    return this->next_id;
}
