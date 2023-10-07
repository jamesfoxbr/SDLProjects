#ifndef ENGINE_H
#define ENGINE_H

#include <stdio.h>
#include <SDL.h>
#include <vector>
#include "Window.h"
#include "Object.h"
#include "Object.h"

class Engine
{
private:
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	SDL_Window* mWindow = nullptr;           //The window we'll be rendering to
	SDL_Surface* mScreenSurface = nullptr;	 //The surface contained by the window

	

public:
	// Player variables
	Object james{50, 50, "images/Idle.png"};

	// Detect Keypress
	bool mUp = false;
	bool mDown = false;
	bool mLeft = false;
	bool mRight = false;

	Engine();
	~Engine();

	void GameLoop();
	void Start();
	void Update();
	void Draw();

	SDL_Surface GetSurface();
};

#endif // !ENGINE_H
