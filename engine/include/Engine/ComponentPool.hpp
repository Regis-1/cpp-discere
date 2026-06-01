#pragma once

#include <Core/Types.h>

constexpr size_t INVALID = SIZE_MAX;

class IComponentPool
{
public:
    virtual ~IComponentPool() = default;
    virtual void remove(Entity entity) = 0;
};

template <typename T>
class ComponentPool : public IComponentPool
{
public:
    ComponentPool()
    {
        this->sparse.resize(MAX_ENTITIES, INVALID);
    }

    void add(Entity entity, const T& component);

    void remove(Entity entity);

    bool has(Entity entity) const;

    T& get(Entity entity);

    const T& get(Entity entity) const;

private:
    std::vector<size_t> sparse;
    std::vector<Entity> dense;

    std::vector<T> data;
};


template <typename T>
void ComponentPool<T>::add(Entity entity, const T& component)
{
    if (has(entity))
    {
        return;
    }

    this->sparse[entity] = this->dense.size();

    this->dense.push_back(entity);
    this->data.push_back(component);
}

template <typename T>
void ComponentPool<T>::remove(Entity entity)
{
    if (!has(entity))
    {
        return;
    }

    size_t index = this->sparse[entity];
    size_t last_index = this->dense.size() - 1;

    if (index != last_index)
    {
        this->dense[index] = this->dense[last_index];
        this->data[index] = std::move(this->data[last_index]);

        Entity moved = this->dense[index];
        this->sparse[moved] = index;
    }

    this->dense.pop_back();
    this->data.pop_back();

    this->sparse[entity] = INVALID;
}

template <typename T>
bool ComponentPool<T>::has(Entity entity) const
{
    if (entity >= this->sparse.size())
    {
        return false;
    }

    size_t index = this->sparse[entity];

    return index != INVALID &&
        index < this->dense.size() &&
        this->dense[index] == entity;
}

template <typename T>
T& ComponentPool<T>::get(Entity entity)
{
    assert(has(entity) && "Entity does not have this component.");

    return this->data[this->sparse[entity]];
}

template <typename T>
const T& ComponentPool<T>::get(Entity entity) const
{
    assert(has(entity) && "Entity does not have this component.");

    return this->data[this->sparse[entity]];
}
