#include "Renderable.h"



Renderable::Renderable()
{
	dirty = true;
}


Renderable::~Renderable()
{
}

Renderable::Pixel::Pixel(int x, int y, char glyph)
{
	this->x = x;
	this->y = y;
	this->glyph = glyph;

	this->lastX = x;
	this->lastY = y;
}


void Renderable::move(int x, int y)
{
	if (x == 0 && y == 0)
		return;

	y = -y;

	for (Pixel &px : pixels)
	{
		px.lastX = px.x;
		px.lastY = px.y;

		px.x += x;
		px.y += y;
	}

	dirty = true;
}


void Renderable::Pixel::setPosition(int x, int y)
{
	this->lastX = this->x;
	this->lastY = this->y;

	this->x = x;
	this->y = y;
}

void Renderable::cleanPixels()
{

}