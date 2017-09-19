#pragma once
#include <vector>
#include <cstdlib>
#include <iostream>
#include <Windows.h>

#include "FrameBuffer.h"

class Renderer
{
public:
	Renderer();
	~Renderer();

	void display();
	void clear();

	bool dirty();

	void addLayer(FrameBuffer);
	void removeLayer(int index);
	void removeAllLayers();
	FrameBuffer* getLayerByName(std::string name);

private:
	std::vector<FrameBuffer> layers;

	FrameBuffer::CharData data;
	FrameBuffer::CharData lastFrame;

	bool isdirty;
};

