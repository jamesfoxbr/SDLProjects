#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <SDL.h>
#include "Window.h"
#include "Player.h"
#include "Game.h"

class Engine
{
private:
	SDL_Window* mWindow = nullptr;           // the window we'll be rendering to
	SDL_Surface* mScreenSurface = nullptr;	 // the surface contained by the window
	Game* game = nullptr;					 // Game to run in the engine

public:
	Engine();
	~Engine();

	SDL_Surface GetSurface();
};

#endif // !ENGINE_H
