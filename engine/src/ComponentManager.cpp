#include "Engine/ComponentManager.hpp"

void ComponentManager::remove_all(Entity entity, const ComponentMask& mask)
{
    for (size_t id = 0; id < mask.size(); ++id)
    {
        if (mask.test(id))
        {
            if (id < pools.size() && pools[id])
            {
                pools[id]->remove(entity);
            }
        }
    }
}
