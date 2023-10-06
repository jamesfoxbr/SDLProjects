#include "Engine.h"

void Engine::GameLoop()
{
    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    //Called one time when the game starts
    Start();

    //While application is running
    while (!quit)
    {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0)
        {
            //User requests quit
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }
        
        //Update game logic
        Update();

        //Update drawings
        SDL_FillRect(mScreenSurface, NULL, SDL_MapRGB(mScreenSurface->format, 0x88, 0x88, 0x88));

        //Update the surface
        SDL_UpdateWindowSurface(mWindow);

        Draw();
    }
}

void Engine::Start()
{
    //Called when a new game starts

}

void Engine::Update()
{
    //Called every frame

}

void Engine::Draw()
{
    //Called every frame

}

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

        //Start gameloop
        GameLoop();
    }
}

Engine::~Engine()
{
    
    //Quit SDL subsystems
    SDL_Quit();
}
