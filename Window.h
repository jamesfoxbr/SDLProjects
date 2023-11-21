#ifndef WINDOW_H
#define WINDOW_H

#include <stdio.h>
#include <SDL.h>
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class Window
{
private:

public:
	SDL_Window* mWindow = nullptr;           //The window we'll be rendering to
	SDL_Surface* mScreenSurface = nullptr;	 //The surface contained by the window

	Window();
	~Window();
};

#endif // !WINDOW_H

