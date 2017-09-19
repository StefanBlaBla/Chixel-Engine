#include "Renderer.h"



Renderer::Renderer()
{
	isdirty = true;
}


Renderer::~Renderer()
{
}

void Renderer::display()
{
	if (layers.size() <= 0)
		return;

	for (FrameBuffer &la : layers)
	{
		if (la.dirty())
			la.update();
	}

	data = layers[0].data;

	for (int i = 1; i < layers.size(); i++)
	{
		for (int y = 0; y < layers[i].data.size(); y++)
		{
			for (int x = 0; x < layers[i].data[y].size(); x++)
			{
				if (layers[i].data[y][x] == ' ')
					continue;

				data[y][x] = layers[i].data[y][x];
			}
		}
	}
	
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int y = 0; y < data.size(); y++)
	{
		for (int x = 0; x < data[y].size(); x++)
		{
			if (lastFrame.size() > 0 && lastFrame[y][x] == data[y][x])
				continue;

			COORD pos = { x, y };
			SetConsoleCursorPosition(output, pos);
			std::cout << data[y][x];
		}
	}

	lastFrame = data;
}

void Renderer::clear()
{
	system("cls");
}

bool Renderer::dirty()
{
	if (isdirty)
	{
		isdirty = false;
		return true;
	}

	if (layers.size() <= 0)
		return false;

	for (FrameBuffer &fb : layers)
	{
		if (fb.dirty())
			return true;
	}

	return false;
}

void Renderer::addLayer(FrameBuffer fb)
{
	layers.push_back(fb);

	isdirty = true;
}

void Renderer::removeLayer(int index)
{
	layers.erase(layers.begin() + index);

	isdirty = true;
}

void Renderer::removeAllLayers()
{
	layers.erase(layers.begin(), layers.end());

	isdirty = true;
}

FrameBuffer* Renderer::getLayerByName(std::string name)
{
	for (FrameBuffer &fb : layers)
	{
		if (fb.name == name)
			return &fb;
	}
}