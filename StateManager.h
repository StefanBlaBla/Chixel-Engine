#pragma once
#include <deque>

#include "Coordinate.h"
#include "MainMenuState.h"

class StateManager
{
public:
	
	// The enum States referenced below is defined in
	// Coordinate.h

	StateManager();
	~StateManager();

	void pushFront(States state);
	void popFront();

	void processInput(char);
	void update();
	void display();

	void changeState(States);

private:

	State* toInstance(States state);

	std::deque<State*> states;
};

