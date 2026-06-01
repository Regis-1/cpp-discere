#include "Game/RenderSystem.h"
#include "Game/Components.h"

#include "Engine/Renderer.h"
#include "Engine/EntityManager.h"
#include "Engine/ComponentManager.hpp"

RenderSystem::RenderSystem(ComponentManager &cm)
{
    this->required.set(cm.get_component_type_id<CTransform>());
    this->required.set(cm.get_component_type_id<CColor>());
}

void RenderSystem::render(Renderer &renderer, const EntityManager &em,
                          const ComponentManager &cm)
{
    for (Entity e = 0; e < em.get_next_id(); ++e)
    {
        if ((em.get_mask(e) & required) != required)
        {
            continue;
        }

        auto &transform = cm.get_component<CTransform>(e);
        auto &color = cm.get_component<CColor>(e);

        renderer.set_draw_color(color.r, color.g, color.b);
        renderer.draw_rectangle(transform.x, transform.y, 16, 16);
    }
}
