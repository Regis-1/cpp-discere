#pragma once

class Renderer;
class Input;

class IGame
{
public:
    virtual void on_start() = 0;
    virtual void on_update(const Input &input) = 0;
    virtual void on_render(Renderer &renderer) = 0;

    virtual ~IGame() = default;
};
