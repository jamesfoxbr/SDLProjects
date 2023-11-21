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

        //Start gameloop
        GameLoop();
    }
}

void Engine::GameLoop()
{
    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event event;

    //Called one time when the game starts
    Start();

    //While application is running
    while (!quit)
    {
        //Handle events on queue
        while (SDL_PollEvent(&event) != 0)
        {
            james.PlayerMovement(event);
            
            //User requests quit
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
        }
                
        //Update game logic
        Update();

        //Fill surface with color
        SDL_FillRect(mScreenSurface, NULL, SDL_MapRGB(mScreenSurface->format, 0x88, 0x88, 0x88));

        Draw();

        //Update the surface
        SDL_UpdateWindowSurface(mWindow); 
    }
}

void Engine::Start()
{
}

void Engine::Update()
{
    if (james.GetPosition().mY >= SCREEN_HEIGHT - 16) {james.SetGrounded(true);}
    else { james.SetGrounded(false);}

    james.AvoidLeaveScreen();
    james.ApplyPlayerMovement();
    james.ApplyGravity();
}

void Engine::Draw()
{
    //Called every frame
    
    james.Display(mScreenSurface);
}

Engine::~Engine()
{ 
    //Quit SDL subsystems
    SDL_Quit();
}

SDL_Surface Engine::GetSurface()
{
    return *mScreenSurface; 
}
