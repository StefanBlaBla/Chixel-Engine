#include "MainMenuState.h"



MainMenuState::MainMenuState()
	: cursorBuffer(80, 24),
	playButton(23, 14, 21, 6)
{
	backgroundBuffer.loadFromFile("display.txt");

	cursor.pixels.push_back(Renderable::Pixel(5, 10, '-'));
	cursor.pixels.push_back(Renderable::Pixel(4, 10, '<'));

	cursorBuffer.registerRenderable(&cursor);

	renderer.addLayer(backgroundBuffer);
	renderer.addLayer(cursorBuffer);
}


MainMenuState::~MainMenuState()
{
}


void MainMenuState::init()
{

}


void MainMenuState::processInput(char pressed)
{
	if (pressed == 'w')
		cursor.move(0, 1);
	else if (pressed == 'a')
		cursor.move(-1, 0);
	else if (pressed == 's')
		cursor.move(0, -1);
	else if (pressed == 'd')
		cursor.move(1, 0);
	else if (pressed == 'k')
	{
		if (playButton.checkOverlap(cursor))
		{
			changeState(States::SnakeState);
		}
	}
}


void MainMenuState::update()
{

}


void MainMenuState::onChange()
{

}