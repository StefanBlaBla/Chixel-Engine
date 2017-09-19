#pragma once
#include "State.h"
#include "TriggerBox.h"

class MainMenuState : public State
{
public:
	MainMenuState();
	~MainMenuState();

	void init() override;
	void update() override;
	void onChange() override;
	void processInput(char) override;

private:
	Renderable cursor;
	TriggerBox playButton;

	// TODO: Should probably make the renderer accept pointers
	// to frame buffer to avoid copying of big amounts of data.
	// Right now these member variables serve no purpose as they
	// could have been created in the constructor or the init() 
	// function. I decided to keep these member variables here
	// just to remind myself that I should probably work on the
	// renderer.
	FrameBuffer backgroundBuffer, cursorBuffer;
};

