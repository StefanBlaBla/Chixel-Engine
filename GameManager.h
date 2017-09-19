#pragma once
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <ctime>
#include <list>

#include "StateManager.h"
#include "Snake.h"
#include "TriggerBox.h"
#include "Renderer.h"
#include "Text.h"

class GameManager
{
public:
	GameManager();
	~GameManager();

	void processInput(char);
	void update();
	void display();

	//Renderable *cursor;
	//Renderer *renderer;

private:

	StateManager stateManager;

	/*TriggerBox playButton;

	bool gameStarted;
	bool canGoThroughWalls;
	Snake snake;
	Text posXTxt, posYTxt, livesTxt;
	std::list<Renderable> apples;

	int lastDirX, lastDirY;

	int lives;

	int appleRate, appleRateCounter;*/
};

