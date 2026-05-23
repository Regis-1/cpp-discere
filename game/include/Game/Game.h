#pragma once

#include "Engine/IGame.h"
#include "Game/World.h"
#include "Game/TileRegistry.h"

#include <memory>

class Renderer;

class Game : public IGame
{
public:
    Game();

    void on_start() override;
    void on_update() override;
    void on_render(Renderer &renderer) override;

private:
    TileRegistry tile_registry;
    TileIds tile_ids;

    std::unique_ptr<World> world;
};
