#pragma once

#include "Engine/Renderer.h"
#include "Engine/InputManager.h"

class IGame;

class Engine
{
public:
    Engine();
    ~Engine();

    bool initialize();

    void run(IGame& game);

private:
    SDL_Window *window;

    Renderer renderer;
    InputManager input_manager;
};
