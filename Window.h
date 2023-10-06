#ifndef WINDOW_H
#define WINDOW_H

#include <stdio.h>
#include <SDL.h>

class Window
{
private:
	const int SCREEN_WIDTH  = 640;
	const int SCREEN_HEIGHT = 480;

	SDL_Window*  mWindow       = nullptr;   //The window we'll be rendering to
	SDL_Surface* mScreenSurface = NULL;		//The surface contained by the window
public:
	Window();
	~Window();
};

#endif // !WINDOW_H

