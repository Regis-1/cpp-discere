#pragma once

#include "Engine/IGame.h"
#include "Game/World.h"
#include "Game/TileRegistry.h"
#include "Game/RenderSystem.h"

#include <memory>

class Renderer;
class Input;

class Game : public IGame
{
public:
    Game();

    void on_start() override;
    void on_update(const Input& input) override;
    void on_render(Renderer& renderer) override;

private:
    TileRegistry tile_registry;
    TileIds tile_ids;

    std::unique_ptr<World> world;

    std::unique_ptr<RenderSystem> render_system;
};
