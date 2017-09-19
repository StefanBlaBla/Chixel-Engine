#pragma once
#include "Renderable.h"

class TriggerBox
{
public:
	TriggerBox();
	TriggerBox(int x, int y, int width, int height);
	~TriggerBox();

	void setPosition(int x, int y);
	void setSize(int width, int height);

	bool checkOverlap(int x, int y);

	bool checkOverlap(Renderable &other);

private:

	int x, y;
	int width, height;
};

