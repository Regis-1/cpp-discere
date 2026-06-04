#include "Engine/InputManager.h"

Action InputManager::scancode_to_action(SDL_Scancode key)
{
    switch (key)
    {
    case SDL_SCANCODE_B:
        return Action::OpenBuildingsMenu;

    case SDL_SCANCODE_I:
        return Action::OpenInventoryMenu;

    case SDL_SCANCODE_V:
        return Action::OpenVillagersMenu;

    case SDL_SCANCODE_P:
        return Action::Pause;


    default:
        return Action::Unknown;
    }
}

void InputManager::update()
{
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_EVENT_QUIT:
            this->input.exit = true;
            break;

        case SDL_EVENT_KEY_DOWN:
            handle_key_down(event.key.scancode);
            break;

        case SDL_EVENT_KEY_UP:
            handle_key_up(event.key.scancode);
            break;
        }
    }
}

Input& InputManager::get_input()
{
    return this->input;
}

void InputManager::begin_frame()
{
    this->input.begin_frame();
}

void InputManager::handle_key_down(SDL_Scancode key)
{
    Action action = scancode_to_action(key);
    size_t idx = static_cast<size_t>(action);

    if (!this->input.down.test(idx))
    {
        this->input.pressed.set(idx);
    }

    this->input.down.set(idx);
}

void InputManager::handle_key_up(SDL_Scancode key)
{
    Action action = scancode_to_action(key);
    size_t idx = static_cast<size_t>(action);

    this->input.down.reset(idx);

    this->input.released.reset(idx);
}
