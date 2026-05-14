#pragma once

#include "Renderer.h"

class IGame;

class Engine
{
public:
    Engine();
    ~Engine();

    bool initialize();

    void run(IGame &game);

private:
    SDL_Window *window;

    Renderer renderer;
};
