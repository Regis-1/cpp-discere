#include "Engine/Engine.h"
#include "Engine/IGame.h"

Engine::Engine()
    : window(nullptr)
{}

Engine::~Engine()
{
    SDL_DestroyWindow(this->window);

    SDL_Quit();
}

bool Engine::initialize()
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                     "SDL could not be initialized. Error: %s\n",
                     SDL_GetError());

        return false;
    }

    this->window = SDL_CreateWindow("Discere", 800, 600, SDL_WINDOW_RESIZABLE);

    if (this->window == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                     "Couldn't create window: %s",
                     SDL_GetError());

        return false;
    }

    // renderer initialization
    if (this->renderer.initialize(this->window) == false)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                     "Couldn't create renderer: %s",
                     SDL_GetError());

        return false;
    }

    return true;
}

void Engine::run(IGame& game)
{
    game.on_start();

    SDL_Event event;

    while (true)
    {
        this->input_manager.begin_frame();
        this->input_manager.update();

        if (this->input_manager.get_input().should_exit())
        {
            break;
        }

        game.on_update(this->input_manager.get_input());

        this->renderer.set_draw_color(0.1f, 0.1f, 0.1f);
        this->renderer.clear_screen();

        game.on_render(this->renderer);

        this->renderer.render();
    }
}
