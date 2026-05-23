#include "Engine/Renderer.h"

Renderer::Renderer()
{}

Renderer::~Renderer()
{
    SDL_DestroyRenderer(this->renderer);
}

bool Renderer::initialize(SDL_Window *window)
{
    if (this->renderer)
    {
        SDL_DestroyRenderer(this->renderer);
    }

    this->renderer = SDL_CreateRenderer(window, nullptr);

    if (this->renderer == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                     "Couldn't create renderer: %s",
                     SDL_GetError());
        return false;
    }

    SDL_SetRenderVSync(this->renderer, 1);

    set_draw_color(0.3, 0.3, 0.3);

    return true;
}

void Renderer::set_draw_color(float r, float g, float b, float a)
{
    SDL_SetRenderDrawColorFloat(this->renderer, r, g, b, a);
}

void Renderer::clear_screen()
{
    SDL_RenderClear(this->renderer);
}

void Renderer::render()
{
    SDL_RenderPresent(this->renderer);
}

void Renderer::draw_rectangle(float x, float y, float width, float height)
{
    SDL_FRect rect {x, y, width, height};
    SDL_RenderFillRect(this->renderer, &rect);
}
