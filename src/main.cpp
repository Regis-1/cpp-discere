#include "Engine/Engine.h"
#include "Game/Game.h"

int main()
{
    Engine engine;
    Game game;

    if (!engine.initialize())
    {
        return 1;
    }

    engine.run(game);

    return 0;
}
