#include "Food.h"
#include "cstdlib"

Food::Food()
{
    Spawn();
}

void Food::Spawn()
{
    pos.x = rand() % WIDTH;
    pos.y = rand() % HEIGTH;
}

Position Food::GetPosition()
{
    return pos;
}