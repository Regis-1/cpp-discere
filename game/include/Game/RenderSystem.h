#pragma once

#include "Core/Types.h"

class Renderer;
class ComponentManager;
class EntityManager;

class RenderSystem
{
public:
    RenderSystem(ComponentManager &cm);

    void render(Renderer &renderer,  const EntityManager &em,
                const ComponentManager &cm);

private:
    ComponentMask required;
};
