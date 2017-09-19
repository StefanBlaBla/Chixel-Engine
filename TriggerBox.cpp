#include "TriggerBox.h"



TriggerBox::TriggerBox()
{
}

TriggerBox::TriggerBox(int x, int y, int width, int height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

TriggerBox::~TriggerBox()
{
}

void TriggerBox::setPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}

void TriggerBox::setSize(int width, int height)
{
	this->width = width;
	this->height = height;
}

bool TriggerBox::checkOverlap(int x, int y)
{
	if (x > this->x && y > this->y && x < (this->x + this->width) && y < (this->y + this->height))
		return true;

	return false;
}

bool TriggerBox::checkOverlap(Renderable &other)
{
	for (Renderable::Pixel &px : other.pixels)
	{
		if (this->checkOverlap(px.x, px.y))
			return true;
	}

	return false;
}