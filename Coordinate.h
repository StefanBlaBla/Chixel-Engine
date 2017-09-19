#pragma once

struct Coordinate
{
	Coordinate(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	int x, y;
};

enum States
{
	MainMenu,
	SnakeState
};