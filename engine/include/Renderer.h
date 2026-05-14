#pragma once

#include "SDL3/SDL.h"

class Renderer
{
public:
    Renderer();
    ~Renderer();

    bool initialize(SDL_Window *window);

    void set_draw_color(float r, float g, float b, float a = SDL_ALPHA_OPAQUE_FLOAT);

    void clear_screen();

    void render();

private:
    SDL_Renderer *renderer;
};
