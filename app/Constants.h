#ifndef CONSTANTS_H
#define CONSTANTS_H

const int WIDTH = 20;
const int HEIGTH = 20;

enum Direction
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

struct Position
{
    int x;
    int y;
};

#endif