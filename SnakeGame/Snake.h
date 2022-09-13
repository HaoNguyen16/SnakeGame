#pragma once
#include <Windows.h>
#include <vector>
using namespace std;
class Snake
{
private:
	COORD pos;
	int length;
	int velocity;
	char direction;
	vector<COORD> body;
public:
	Snake(COORD pos, int velocity);
	// function to change direction of the snake
	void changeDirection(char direct); 
	// function to move the snake
	void moveSnake();
	// function to get position of the snake
	COORD getpos();
	// function to check if the snake eat the food
	bool eaten(COORD food_pos);
	// function to growth the snake
	void growth();
	// function to end the game when the snake collided
	bool collided();
	//function to get the snake's body
	vector<COORD> get_body();
};