#include "Window.h"

Window::Window()
	:
	mWindow(SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN))
{
	if (mWindow == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Get window surface
		mScreenSurface = SDL_GetWindowSurface(mWindow);
	}
}

Window::~Window()
{
	//Deallocate surface
	SDL_FreeSurface(mScreenSurface);
	mScreenSurface = nullptr;

	//Destroy window
	SDL_DestroyWindow(mWindow);
	mWindow = nullptr;
}
