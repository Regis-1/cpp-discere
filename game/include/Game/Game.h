#pragma once

#include "Engine/IGame.h"

class Game : public IGame
{
public:
    void on_start() override;
    void on_update() override;
    void on_render() override;
};
