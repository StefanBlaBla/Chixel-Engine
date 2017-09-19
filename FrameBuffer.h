#pragma once
#include <string>
#include <vector>
#include <fstream>

#include "Renderable.h"

class FrameBuffer
{
public:
	typedef std::vector<std::vector<char>> CharData;

	FrameBuffer();
	FrameBuffer(int width, int height);
	FrameBuffer(int width, int height, std::string name);
	~FrameBuffer();

	void loadFromFile(const char* fileName);
	void update();
	void registerRenderable(Renderable*);
	void deleteRenderable(Renderable*);

	bool dirty();

	CharData data;
	std::string name;

private:

	std::vector<Renderable*> renderables;
	bool isdirty;

};

