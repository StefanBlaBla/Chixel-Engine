#include "FrameBuffer.h"



FrameBuffer::FrameBuffer()
{
	isdirty = true;
}

FrameBuffer::FrameBuffer(int width, int height)
{
	for (int y = 0; y < height; y++)
	{
		std::vector<char> thisLine;

		for (int x = 0; x < width; x++)
		{
			thisLine.push_back(' ');
		}

		data.push_back(thisLine);
	}

	isdirty = true;
}

FrameBuffer::FrameBuffer(int width, int height, std::string name)
{
	for (int y = 0; y < height; y++)
	{
		std::vector<char> thisLine;

		for (int x = 0; x < width; x++)
		{
			thisLine.push_back(' ');
		}

		data.push_back(thisLine);
	}

	this->name = name;

	isdirty = true;
}


FrameBuffer::~FrameBuffer()
{
}

void FrameBuffer::loadFromFile(const char* fileName)
{
	std::ifstream file;
	file.open(fileName);

	std::string line;

	while (std::getline(file, line))
	{
		std::vector<char> thisLine;
		for (char &ch : line)
		{
			if (ch == '0')
				ch = ' ';

			thisLine.push_back((char)ch);
		}

		data.push_back(thisLine);
	}

	file.close();
}

void FrameBuffer::update()
{
	for (int i = 0; i < renderables.size(); i++)
	{
		if (renderables[i]->dirty)
		{
			for (Renderable::Pixel &px : renderables[i]->pixels)
			{
				if (px.lastY >= 0 && px.lastY < data.size() && px.lastX >= 0 && px.lastY < data[0].size())
					data[px.lastY][px.lastX] = ' ';
			}

			for (Renderable::Pixel &px : renderables[i]->pixels)
			{
				if (px.y >= 0 && px.y < data.size() && px.x >= 0 && px.x < data[0].size())
					data[px.y][px.x] = px.glyph;
			}

			renderables[i]->dirty = false;
		}
	}
}

void FrameBuffer::registerRenderable(Renderable* rend)
{
	renderables.push_back(rend);

	isdirty = true;
}

void FrameBuffer::deleteRenderable(Renderable* rend)
{
	this->update();

	for (Renderable::Pixel &px : rend->pixels)
	{
		data[px.y][px.x] = ' ';
	}

	auto it = std::find(renderables.begin(), renderables.end(), rend);

	if (it != renderables.end())
		renderables.erase(it);

	isdirty = true;
}

bool FrameBuffer::dirty()
{
	if (isdirty)
	{
		isdirty = false;

		return true;
	}

	for (Renderable* rend : renderables)
	{
		if (rend->dirty)
			return true;
	}

	return false;
}