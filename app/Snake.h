#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "Constants.h"

class Snake
{
public:
    Snake();
    void Move();
    void Grow();
    bool CheckCollision();
    Position GetHeadPosition();
    std::vector<Position> GetBody();

    Direction dir;

private:
    std::vector<Position> body;
};

#endif