#include "Engine/Engine.h"
#include "Engine/IGame.h"

void Engine::run(IGame &game)
{
    game.on_start();
    game.on_update();
}
