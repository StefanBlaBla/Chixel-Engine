#include "StateManager.h"
#include <iostream>



StateManager::StateManager()
{
}


StateManager::~StateManager()
{
}


State* StateManager::toInstance(States state)
{
	if (state == States::MainMenu)
		return new MainMenuState();
}


void StateManager::pushFront(States state)
{
	State *s = toInstance(state);
	s->changeState = std::bind(&StateManager::changeState, this, std::placeholders::_1); //[&](States state) { this->changeState(state);  }; // This is the problem
	s->init();

	states.push_front(s);
}


void StateManager::popFront()
{
	if (states.size() == 0)
		return;

	states.front()->onChange();
	states.pop_front();
}


void StateManager::processInput(char pressed)
{
	if (states.size() == 0)
		return;

	states.front()->processInput(pressed);
}


void StateManager::update()
{
	if (states.size() == 0)
		return;

	states.front()->update();
}


void StateManager::display()
{
	if (states.size() == 0)
		return;

	states.front()->display();
}


void StateManager::changeState(States state)
{
	std::cout << "Hello!";

	this->popFront();
	this->pushFront(state);
}