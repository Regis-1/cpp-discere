#pragma once

class IGame
{
public:
    virtual void on_start() = 0;
    virtual void on_update() = 0;
    virtual void on_render() = 0;

    virtual ~IGame() = default;
};
