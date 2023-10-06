#ifndef ENGINE_H
#define ENGINE_H

#include <stdio.h>
#include <SDL.h>
#include "Window.h"

class Engine
{
private:
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	SDL_Window* mWindow = nullptr;           //The window we'll be rendering to
	SDL_Surface* mScreenSurface = nullptr;	 //The surface contained by the window

	void GameLoop();
	void Start();
	void Update();
	void Draw();

public:
	Engine();
	~Engine();
};

#endif // !ENGINE_H
