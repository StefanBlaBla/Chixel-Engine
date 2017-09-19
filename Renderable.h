#pragma once
#include <vector>

class Renderable
{
public:
	struct Pixel
	{
		Pixel(int x, int y, char glyph);
		char glyph;
		int x, y, lastX, lastY;

		void setPosition(int x, int y);
	};

	Renderable();
	~Renderable();

	void move(int x, int y);

	void cleanPixels();

	bool dirty;

	std::vector<Pixel> pixels;

};

