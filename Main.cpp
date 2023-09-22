#include <SDL.h>
#include <stdio.h>

// screen dimensions constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


int main(int argc, char* argv[])
{
	// The window we'll be rendering to
	SDL_Window* window = NULL;

	// the surface constained by the window
	SDL_Surface* screenSurface = NULL;

	// initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL cound not initialized! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		// create window
		window = SDL_CreateWindow("SDL Tutorial", 
			SDL_WINDOWPOS_UNDEFINED, 
			SDL_WINDOWPOS_UNDEFINED, 
			SCREEN_WIDTH, 
			SCREEN_HEIGHT, 
			SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			// Get window surface
			screenSurface = SDL_GetWindowSurface(window);

			//full the surface with white
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x00, 0xff, 0xff));

			// update the surface
			SDL_UpdateWindowSurface(window);

			//Hack to get window to stay up
			SDL_Event e; bool quit = false; while (quit == false){ while (SDL_PollEvent(&e)){ if (e.type == SDL_QUIT) quit = true; } }
		}
	}

	// destroy the window
	SDL_DestroyWindow(window);

	// quit SDL subsystems
	SDL_Quit();

	return 0;
}