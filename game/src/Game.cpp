#include "Game/Game.h"

#include <iostream>

void Game::on_start()
{
    std::cout << "hello from on_start" << std::endl;
}

void Game::on_update()
{
    std::cout << "hello from on_update" << std::endl;
}

void Game::on_render()
{
    std::cout << "hello from on_render" << std::endl;
}
