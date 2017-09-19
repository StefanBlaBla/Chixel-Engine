#include "GameManager.h"



GameManager::GameManager()
{
	// Hide the cursor
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);

	srand(time(NULL));

	/*playButton = TriggerBox(23, 14, 21, 6);

	gameStarted = false;
	lastDirX = -1;
	lastDirY = 0;

	canGoThroughWalls = true;
	lives = 3;

	appleRate = 30;
	appleRateCounter = 0;*/

	stateManager.pushFront(States::MainMenu);
}


GameManager::~GameManager()
{
}

void GameManager::processInput(char pressed)
{
	stateManager.processInput(pressed);

	/*if (gameStarted)
	{
		if (pressed == 'w')
		{
			lastDirX = 0;
			lastDirY = 1;
		}
		else if (pressed == 'a')
		{
			lastDirX = -1;
			lastDirY = 0;
		}
		else if (pressed == 's')
		{
			lastDirX = 0;
			lastDirY = -1;
		}
		else if (pressed == 'd')
		{
			lastDirX = 1;
			lastDirY = 0;
		}
		else if (pressed == 'e')
			snake.addPixel();

		return;
	}

	if (pressed == 'w')
		cursor->move(0, 1);
	else if (pressed == 'a')
		cursor->move(-1, 0);
	else if (pressed == 's')
		cursor->move(0, -1);
	else if (pressed == 'd')
		cursor->move(1, 0);
	else if (pressed == 'k')
	{
		if (playButton.checkOverlap(*cursor))
		{
			gameStarted = true;

			renderer->removeAllLayers();

			FrameBuffer background;
			background.loadFromFile("mainMap.txt");

			FrameBuffer snakeBuffer(80, 24, "snakebuff");
			snake = Snake();
			snake.pixels.push_back(Renderable::Pixel(3, 4, '@'));
			snake.pixels.push_back(Renderable::Pixel(4, 4, '@'));
			snake.pixels.push_back(Renderable::Pixel(5, 4, '@'));
			snake.pixels.push_back(Renderable::Pixel(6, 4, '@'));

			posXTxt = Text();
			posXTxt.setPosition(Coordinate(66, 4));
			posXTxt.setText("PosX:");

			posYTxt = Text();
			posYTxt.setPosition(Coordinate(66, 5));
			posYTxt.setText("PosY:");


			livesTxt = Text();
			livesTxt.setPosition(Coordinate(66, 6));
			livesTxt.setText("Lives: " + std::to_string(lives));

			snakeBuffer.registerRenderable(&snake);

			background.registerRenderable(&posXTxt);
			background.registerRenderable(&posYTxt);
			background.registerRenderable(&livesTxt);

			renderer->addLayer(background);
			renderer->addLayer(snakeBuffer);
		}
	}*/
}

void GameManager::update()
{
	stateManager.update();

	//if (gameStarted)
	//{
	//	appleRateCounter++;

	//	if (appleRateCounter > appleRate)
	//	{
	//		apples.push_back(Renderable());
	//		apples.back().pixels.push_back(Renderable::Pixel(rand() % 61, rand() % 23, '%'));
	//		apples.back().dirty = true;

	//		renderer->getLayerByName("snakebuff")->registerRenderable(&apples.back());

	//		appleRateCounter = 0;
	//	}

	//	bool canMove = true;

	//	if (canMove)
	//		snake.moveSnake(lastDirX, lastDirY);

	//	if (!canGoThroughWalls)
	//	{
	//		for (Renderable::Pixel &px : snake.pixels)
	//		{
	//			if (px.y > 23 || px.y < 0)
	//				snake.move(-lastDirX, -lastDirY);
	//			else if (px.x > 60 || px.x < 0)
	//				snake.move(-lastDirX, -lastDirY);
	//		}
	//	}
	//	else
	//	{
	//		Renderable::Pixel &px = snake.pixels[0];

	//		if (px.y > 23)
	//		{
	//			px.setPosition(px.x, 0);
	//			snake.dirty = true;
	//		}
	//		else if (px.y < 0)
	//		{
	//			px.setPosition(px.x, 23);
	//			snake.dirty = true;
	//		}
	//		else if (px.x > 60)
	//		{
	//			px.setPosition(0, px.y);
	//			snake.dirty = true;
	//		}
	//		else if (px.x < 0)
	//		{
	//			px.setPosition(60, px.y);
	//			snake.dirty = true;
	//		}
	//	}

	//	posXTxt.setText("PosX: " + std::to_string(snake.pixels[0].x));
	//	posYTxt.setText("PosY: " + std::to_string(snake.pixels[0].y));

	//	if (snake.checkCollisionItself())
	//	{
	//		if (lives > 1)
	//		{
	//			lives--;

	//			livesTxt.setText("Lives: " + std::to_string(lives));
	//			
	//			// Reset game
	//			renderer->getLayerByName("snakebuff")->deleteRenderable(&snake);

	//			snake = Snake();
	//			snake.pixels.push_back(Renderable::Pixel(3, 4, '@'));
	//			snake.pixels.push_back(Renderable::Pixel(4, 4, '@'));
	//			snake.pixels.push_back(Renderable::Pixel(5, 4, '@'));
	//			snake.pixels.push_back(Renderable::Pixel(6, 4, '@'));
	//			snake.dirty = true;

	//			renderer->getLayerByName("snakebuff")->registerRenderable(&snake);

	//			lastDirX = -1;
	//			lastDirY = 0;
	//		}
	//		else
	//		{
	//			// GAME OVER
	//			renderer->removeAllLayers();

	//			FrameBuffer gameOver;
	//			gameOver.loadFromFile("gameover.txt");

	//			renderer->addLayer(gameOver);

	//			gameStarted = false;
	//		}
	//	}

	//	for (Renderable &ren : apples)
	//	{
	//		if (ren.pixels[0].x == snake.pixels[0].x && ren.pixels[0].y == snake.pixels[0].y)
	//		{
	//			snake.addPixel();

	//			renderer->getLayerByName("snakebuff")->deleteRenderable(&ren);
	//		}
	//	}
	//}
}


void GameManager::display()
{
	stateManager.display();
}