// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include "Snake.h"
#include <conio.h>
#include "Food.h"
#include <ctime>

#define WIDTH 50
#define HEIGHT 25
using namespace std;
Snake snake({ WIDTH / 2, HEIGHT / 2 }, 1);
Food food;
void board()
{
    COORD snake_pos = snake.getpos();
    COORD food_pos = food.get_pos();
    vector<COORD> snake_body = snake.get_body();
    for (int i = 0; i < HEIGHT; i++)
    {
        cout << "\t\t#";
        for (int j = 0; j < WIDTH - 2 ; j++)
        {
            if (i == 0 || i == HEIGHT - 1)
                cout << "#";
            else if (i == snake_pos.Y && j+1 == snake_pos.X)
                cout << "@";
            else if (i == food_pos.Y && j+1 == food_pos.X)
                cout << "*";
            else
            {
               bool isBodyPart = false;
                for (int k = 0; k < snake_body.size(); k++)
                {
                    if (i == snake_body[k].Y && j + 1 == snake_body[k].X)
                    {
                        cout << "o";
                        isBodyPart = true;
                        break;
                    }
                }
                if (!isBodyPart)
                    cout << " ";
            }
        }
        cout << "#\n";
    }
}
int main()
{
    srand(time(NULL));
    bool game_over = false;
    while(!game_over)
    {
        board();
        if (_kbhit())
        {
            switch (_getch())
            {
            case 'w': snake.changeDirection('w');
                break;
            case 's': snake.changeDirection('s');
                break;
            case 'a': snake.changeDirection('a');
                break;
            case 'd': snake.changeDirection('d');
                break;

            }
            snake.moveSnake();
            if (snake.eaten(food.get_pos()))
            {
                food.generateFood();
                snake.growth();
            }
            if (snake.collided())
                game_over = true;
        }
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
    }
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
    system("cls");
    cout << "GAME OVER!!!";
}