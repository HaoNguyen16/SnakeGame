#pragma once
#include <Windows.h>
#include <cstdlib>
#define WIDTH 50
#define HEIGHT 25
class Food {
private:
	COORD pos;
public:
	Food();
	void generateFood();
	COORD get_pos();
};