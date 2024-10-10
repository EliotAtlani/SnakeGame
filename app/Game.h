#ifndef GAME_H
#define GAME_H

#include "Snake.h"
#include "Food.h"
class Game
{
public:
    Game();
    void Run();

private:
    void Draw();
    void Input();
    void Logic();
    bool gameOver;
    Snake snake;
    Food food;
    int score;
};

#endif