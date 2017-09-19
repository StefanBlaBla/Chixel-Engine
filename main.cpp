#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <ctime>
#include <windows.h>

#include "GameManager.h"
#include "Renderer.h"
using namespace std;

int main()
{
	GameManager gm;

	/*FrameBuffer background;

	background.loadFromFile("display.txt");

	FrameBuffer cursorBuffer(80, 24);

	Renderable cursor;
	cursor.pixels.push_back(Renderable::Pixel(5, 10, '-'));
	cursor.pixels.push_back(Renderable::Pixel(4, 10, '<'));

	cursorBuffer.registerRenderable(&cursor);
	gm.cursor = &cursor;

	Renderer renderer;
	gm.renderer = &renderer;

	renderer.addLayer(background);
	renderer.addLayer(cursorBuffer);

	renderer.display();*/

	while (true)
	{
		if (_kbhit())
		{
			int input = _getch();
			gm.processInput((char)input);
		}

		gm.update();

		//if (renderer.dirty())
		//{
		//	//renderer.clear();
		//	renderer.display();
		//}
		gm.display();

		Sleep(70);
	}

	return 0;
}