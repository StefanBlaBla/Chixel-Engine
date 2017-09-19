#include "Snake.h"



Snake::Snake()
{
}


Snake::~Snake()
{
}


void Snake::moveSnake(int x, int y)
{
	if (x == 0 && y == 0)
		return;

	y = -y;

	pixels[0].lastX = pixels[0].x;
	pixels[0].lastY = pixels[0].y;

	pixels[0].x += x;
	pixels[0].y += y;

	for (int i = 1; i < pixels.size(); i++)
	{
		pixels[i].lastX = pixels[i].x;
		pixels[i].lastY = pixels[i].y;

		pixels[i].x = pixels[i - 1].lastX;
		pixels[i].y = pixels[i - 1].lastY;
	}

	dirty = true;
}

void Snake::addPixel()
{
	pixels.push_back(Renderable::Pixel(pixels[pixels.size() - 1].lastX, pixels[pixels.size() - 1].lastY, pixels[0].glyph));
}

bool Snake::checkCollisionItself()
{
	for (int x = 0; x < pixels.size(); x++)
	{
		for (int y = 0; y < pixels.size(); y++)
		{
			if (x == y)
				continue;

			if (pixels[x].x == pixels[y].x && pixels[x].y == pixels[y].y)
				return true;
		}		
	}

	return false;
}