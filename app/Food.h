#ifndef FOOD_H
#define FOOD_H

#include "Constants.h"

class Food
{
public:
    Food();
    void Spawn();
    Position GetPosition();

private:
    Position pos;
};

#endif