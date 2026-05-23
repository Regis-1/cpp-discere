#pragma once

#include "Engine/Renderer.h"

class IGame
{
public:
    virtual void on_start() = 0;
    virtual void on_update() = 0;
    virtual void on_render(Renderer &renderer) = 0;

    virtual ~IGame() = default;
};
