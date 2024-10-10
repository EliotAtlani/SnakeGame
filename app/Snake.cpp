#include "Snake.h"

Snake::Snake()
{
    Position initPos = {WIDTH / 2, HEIGTH / 2};
    body.push_back(initPos);
    dir = STOP;
}

void Snake::Move()
{
    Position newHead = body.front();

    switch (dir)
    {
    case LEFT:
        newHead.x--;
        break;
    case RIGHT:
        newHead.x++;
        break;
    case UP:
        newHead.y--;
        break;
    case DOWN:
        newHead.y++;
        break;
    default:
        break;
    }

    body.insert(body.begin(), newHead);
    body.pop_back();
}

void Snake::Grow()
{
    Position tail = body.back();
    body.push_back(tail);
}

bool Snake::CheckCollision()
{
    Position head = body.front();

    if (head.x >= WIDTH || head.x < 0 || head.y >= HEIGTH || head.y < 0)
        return true;

    for (size_t i = 1; i < body.size(); i++)
    {
        if (body[i].x == head.x && body[i].y == head.y)
            return true;
    }

    return false;
}

Position Snake::GetHeadPosition()
{
    return body.front();
}

std::vector<Position> Snake::GetBody()
{
    return body;
}