#include "Snake.h"
#define WIDTH 50
#define HEIGHT 25
Snake::Snake(COORD pos, int velocity)
{
	this->pos = pos;
	this->velocity = velocity;
	length = 1;
	direction = 'n';
}
void Snake::changeDirection(char direct)
{
	direction = direct;
}
vector<COORD> Snake::get_body()
{
	return body;
}
void Snake::moveSnake()
{
	switch (direction)
	{
	case 'w':
		pos.Y -= velocity;
		break;
	case 's':
		pos.Y += velocity;
		break;
	case 'a':
		pos.X -= velocity;
		break;
	case 'd':
		pos.X += velocity;
		break;
	}
	body.push_back(pos);
	if (body.size() > length)
		body.erase(body.begin());
}
COORD Snake::getpos() 
{
	return pos;
}
bool Snake::eaten(COORD food_pos)
{
	if (food_pos.X == pos.X && food_pos.Y == pos.Y)
		return true;
	else return false;
}
void Snake::growth()
{
	length++;
}
bool Snake::collided()
{
	if (pos.X<1 || pos.X>WIDTH - 2 || pos.Y<1 || pos.Y>HEIGHT - 2)
		return true;
	else return false;
}
