#pragma once
#include <list>
#include <ctime>
#include <cstdlib>

#include "State.h"
#include "Snake.h"
#include "Text.h"

class SnakeState : public State
{
public:
	SnakeState();
	~SnakeState();

	void init() override;
	void update() override;
	void onChange() override;
	void processInput(char) override;

private:

	bool gameStarted;
	bool canGoThroughWalls;
	Snake snake;
	Text posXTxt, posYTxt, livesTxt;
	std::list<Renderable> apples;

	int lastDirX, lastDirY;

	int lives;

	int appleRate, appleRateCounter;

};

