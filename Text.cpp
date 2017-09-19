#include "Text.h"



Text::Text()
	: pos(0, 0)
{
	
}


Text::Text(const Coordinate &pos, const std::string &text)
	: pos(0, 0)
{
	this->setPosition(pos);
	this->setText(text);
}


Text::~Text()
{
}


void Text::setText(const std::string &text)
{
	for (int i = 0; i < text.size(); i++)
	{
		if (i >= pixels.size())
		{
			pixels.push_back(Pixel(pos.x + i, pos.y, text[i]));
		}
		else
		{
			pixels[i].glyph = text[i];

			if (pixels[i].x != pos.x + i && pixels[i].y != pos.y)
				pixels[i].setPosition(pos.x + i, pos.y);	
		}
	}

	for (int i = text.size(); i < pixels.size(); i++)
	{
		pixels[i].glyph = ' ';
	}

	dirty = true;
}


std::string Text::getText() const
{
	return text;
}


void Text::setPosition(const Coordinate &pos)
{
	this->pos.x = pos.x;
	this->pos.y = pos.y;

	dirty = true;
}


Coordinate Text::getPosition()
{
	return pos;
}