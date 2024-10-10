// Game.cpp
#include "Game.h"
#include <iostream>
#include <cstdlib>  // For system("clear")
#include <unistd.h> // For usleep()
#include "NonBlockingInput.h"

Game::Game()
{
    gameOver = false;
    score = 0;
}

void Game::Run()
{
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        usleep(100000); // Sleep for 100 milliseconds
    }
    std::cout << "Game Over!" << std::endl;
}

void Game::Draw()
{
    system("clear"); // Clear console on Unix systems

    // Draw top wall
    for (int i = 0; i < WIDTH + 2; i++)
        std::cout << "#";
    std::cout << "  Score: " << score;
    std::cout << std::endl;

    // Draw sides and snake
    for (int y = 0; y < HEIGTH; y++)
    {
        for (int x = -1; x <= WIDTH; x++)
        {
            if (x == -1 || x == WIDTH)
                std::cout << "#";
            else if (x == snake.GetHeadPosition().x && y == snake.GetHeadPosition().y)
                std::cout << "O";
            else if (x == food.GetPosition().x && y == food.GetPosition().y)
                std::cout << "F";
            else
            {
                bool print = false;
                for (auto pos : snake.GetBody())
                {
                    if (pos.x == x && pos.y == y)
                    {
                        std::cout << "o";
                        print = true;
                        break;
                    }
                }
                if (!print)
                    std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    // Draw bottom wall
    for (int i = 0; i < WIDTH + 2; i++)
        std::cout << "#";
    std::cout << std::endl;
}

void Game::Input()
{
    if (kbhit())
    {
        switch (getch())
        {
        case 'a':
            if (snake.dir != RIGHT)
                snake.dir = LEFT;
            break;
        case 'd':
            if (snake.dir != LEFT)
                snake.dir = RIGHT;
            break;
        case 'w':
            if (snake.dir != DOWN)
                snake.dir = UP;
            break;
        case 's':
            if (snake.dir != UP)
                snake.dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

void Game::Logic()
{
    snake.Move();

    // Check collision with food
    if (snake.GetHeadPosition().x == food.GetPosition().x &&
        snake.GetHeadPosition().y == food.GetPosition().y)
    {
        snake.Grow();
        score++;
        food.Spawn();
    }
    else
    {
        // Check collision with walls or self
        if (snake.CheckCollision())
        {
            gameOver = true;
        }
    }
}
