#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <SDL.h>
#include <vector>
#include "Window.h"
#include "Player.h"

class Engine
{
private:
	SDL_Window* mWindow = nullptr;           //The window we'll be rendering to
	SDL_Surface* mScreenSurface = nullptr;	 //The surface contained by the window

public:
	// Player variable
	Player james{50, 50, "images/Idle.png"};

	Engine();
	~Engine();

	void GameLoop();
	void Start();
	void Update();
	void Draw();

	SDL_Surface GetSurface();
};

#endif // !ENGINE_H
