// Main.cpp
#include "Game.h"
#include <cstdlib>
#include <ctime>

int main()
{
    srand(static_cast<unsigned int>(time(nullptr))); // Seed the random number generator

    Game game;
    game.Run();
    return 0;
}
