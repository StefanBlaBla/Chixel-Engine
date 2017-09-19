#pragma once
#include <functional>

#include "Renderer.h"
#include "Coordinate.h"

class State
{
public:
	State() {};
	~State() {};

	virtual void init() {};
	virtual void update() {};
	virtual void onChange() {};
	virtual void processInput(char) {};
	virtual void display() { renderer.display(); };

	std::function<void(States)> changeState;

protected:

	Renderer renderer;

};

