#pragma once

#include <memory>
#include <cassert>
#include <vector>

#include "Engine/ComponentPool.hpp"
#include "Core/Types.h"

inline ComponentTypeId next_component_type_id = 0;

class ComponentManager
{
public:
    template <typename T>
    ComponentTypeId get_component_type_id() const;

    template <typename T>
    void add_component(Entity entity, const T& component);

    template <typename T>
    void remove_component(Entity entity);

    template <typename T>
    bool has_component(Entity entity) const;

    template <typename T>
    T& get_component(Entity entity);

    template <typename T>
    const T& get_component(Entity entity) const;

    template <typename T>
    ComponentPool<T>& get_pool();

    template <typename T>
    const ComponentPool<T>& get_pool() const;

    void remove_all(Entity entity, const ComponentMask& mask);

private:
    std::vector<std::unique_ptr<IComponentPool>> pools;
};

template <typename T>
ComponentTypeId ComponentManager::get_component_type_id() const
{
    static ComponentTypeId id = next_component_type_id++;

    return id;
}

template <typename T>
void ComponentManager::add_component(Entity entity, const T& component)
{
    get_pool<T>().add(entity, component);
}

template <typename T>
void ComponentManager::remove_component(Entity entity)
{
    get_pool<T>().remove(entity);
}

template <typename T>
bool ComponentManager::has_component(Entity entity) const
{
    return get_pool<T>().has(entity);
}

template <typename T>
T& ComponentManager::get_component(Entity entity)
{
    return get_pool<T>().get(entity);
}

template <typename T>
const T& ComponentManager::get_component(Entity entity) const
{
    return get_pool<T>().get(entity);
}

template <typename T>
ComponentPool<T>& ComponentManager::get_pool()
{
    auto id = get_component_type_id<T>();

    if (id >= this->pools.size())
    {
        pools.resize(id + 1);
    }

    if (!pools[id])
    {
        pools[id] = std::make_unique<ComponentPool<T>>();
    }

    return *static_cast<ComponentPool<T>*>(pools[id].get());
}

template <typename T>
const ComponentPool<T>& ComponentManager::get_pool() const
{
    auto id = get_component_type_id<T>();

    assert(id < pools.size());
    assert(pools[id]);

    return *static_cast<ComponentPool<T>*>(pools[id].get());
}
