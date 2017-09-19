#pragma once
#include "Renderable.h"
#include "Coordinate.h"

class Text : public Renderable
{
public:
	Text();
	Text(const Coordinate &pos, const std::string &text);

	~Text();

	void setText(const std::string &text);
	std::string getText() const;

	void setPosition(const Coordinate &pos);
	Coordinate getPosition();
	

private:

	std::string text;
	Coordinate pos;
};

