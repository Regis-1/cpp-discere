#include "Game/Game.h"

#include <iostream>

Game::Game()
{}

void Game::on_start()
{
    std::cout << "hello from on_start" << std::endl;

    this->tile_ids = register_tiles(this->tile_registry);

    this->world = std::make_unique<World>(this->tile_ids);
}

void Game::on_update()
{
    std::cout << "hello from on_update" << std::endl;
}

void Game::on_render(Renderer &renderer)
{
    std::cout << "hello from on_render" << std::endl;
    this->world->get_tilemap().draw(renderer, this->tile_registry);
}
