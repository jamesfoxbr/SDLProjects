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
    SDL_Event e;

    //Called one time when the game starts
    Start();

    //While application is running
    while (!quit)
    {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0)
        {
            PlayerMovement(e);
            
            //User requests quit
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }

        // Apply player movement
        ApplyPlayerMovement();
                
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
    //Called every frame   
}

void Engine::Draw()
{
    //Called every frame
    james.Display(playerX, playerY, mScreenSurface);
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

void Engine::PlayerMovement(const SDL_Event &e)
{
    if (e.type == SDL_KEYDOWN)
    {
        if (e.key.keysym.sym == SDLK_RIGHT) {moveRight = true;}
        if (e.key.keysym.sym == SDLK_LEFT) { moveLeft  = true;}
        if (e.key.keysym.sym == SDLK_DOWN) { moveDown  = true; }
        if (e.key.keysym.sym == SDLK_UP)   { moveUp    = true; }
    }
    if (e.type == SDL_KEYUP)
    {
        if (e.key.keysym.sym == SDLK_RIGHT) {moveRight = false;}
        if (e.key.keysym.sym == SDLK_LEFT) { moveLeft  = false;}
        if (e.key.keysym.sym == SDLK_DOWN) { moveDown  = false; }
        if (e.key.keysym.sym == SDLK_UP)   { moveUp    = false; }
    }
}

void Engine::ApplyPlayerMovement()
{
    if (moveRight) { playerX += playerSpeed; }
    if (moveLeft)  { playerX -= playerSpeed; }
    if (moveDown)  { playerY += playerSpeed; }
    if (moveUp)    { playerY -= playerSpeed; }
}
