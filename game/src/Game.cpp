#include "Game/Game.h"

Game::Game()
{}

void Game::on_start()
{
    this->tile_ids = register_tiles(this->tile_registry);

    this->world = std::make_unique<World>(this->tile_ids);
    this->render_system = std::make_unique<RenderSystem>(*this->world);
}

void Game::on_update(const Input &input)
{
    this->world->update(input);
}

void Game::on_render(Renderer &renderer)
{
    this->render_system->render(renderer, this->tile_registry);
}
