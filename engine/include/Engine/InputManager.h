#pragma once

#include "SDL3/SDL.h"
#include "Engine/Input.h"

class InputManager
{
public:
    InputManager() = default;

    Action scancode_to_action(SDL_Scancode key);

    void update();

    Input& get_input();

    void begin_frame();

private:
    void handle_key_down(SDL_Scancode key);

    void handle_key_up(SDL_Scancode key);


    SDL_Event event;

    Input input;
};
