#pragma once
#include "Renderable.h"

class Snake : public Renderable
{
public:

	Snake();
	~Snake();

	void moveSnake(int x, int y);
	void addPixel();
	bool checkCollisionItself();

private:

};

