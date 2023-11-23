#include "Engine.h"
#include "Main.h"

Engine::Engine()
{
    //Create window
    mWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }
    else
    {
        //Get window surface
        mScreenSurface = SDL_GetWindowSurface(mWindow);

        //Start new game and gameloop
        Game *game = new Game(mScreenSurface, mWindow);
 
    }
}

Engine::~Engine()
{ 
    //Quit SDL subsystems
    delete game;
    SDL_Quit();
}

SDL_Surface Engine::GetSurface()
{
    return *mScreenSurface; 
}
