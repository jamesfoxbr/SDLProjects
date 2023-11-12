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
            PlayerMovement(event);
            
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
    if (playerY >= SCREEN_HEIGHT - 16) { grounded = true; }
    else { grounded = false; }

    AvoidLeaveScreen();
    ApplyPlayerMovement();
    ApplyGravity();
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

void Engine::PlayerMovement(const SDL_Event &event)
{

    if (event.type == SDL_KEYDOWN)
    {
        if (event.key.keysym.sym == SDLK_RIGHT) {moveRight = true;}
        if (event.key.keysym.sym == SDLK_LEFT)  {moveLeft  = true;}
        if (event.key.keysym.sym == SDLK_DOWN)  {moveDown  = true;}
        if (event.key.keysym.sym == SDLK_UP)    {moveUp    = true;}
        // Jump
        if (event.key.keysym.sym == SDLK_SPACE && grounded) { jumping = true; }
    }
    if (event.type == SDL_KEYUP)
    {
        if (event.key.keysym.sym == SDLK_RIGHT) {moveRight = false;}
        if (event.key.keysym.sym == SDLK_LEFT)  {moveLeft  = false;}
        if (event.key.keysym.sym == SDLK_DOWN)  {moveDown  = false;}
        if (event.key.keysym.sym == SDLK_UP)    {moveUp    = false;}
        // Jump
        if (event.key.keysym.sym == SDLK_SPACE) { jumping = false; }
    }
}

void Engine::AvoidLeaveScreen()
{
    if (playerX <= 0) { playerX = 0; }
    if (playerX >= SCREEN_WIDTH - 16) { playerX = SCREEN_WIDTH - 16; }
    if (playerY <= 0) { playerY = 0; }
    if (playerY >= SCREEN_HEIGHT - 16) { playerY = SCREEN_HEIGHT - 16; PlayerVelocityY = 0; }
}

void Engine::ApplyPlayerMovement()
{
    if (moveRight) { playerX += playerSpeed; }
    if (moveLeft)  { playerX -= playerSpeed; }
    if (moveDown)  { playerY += playerSpeed; }
    if (moveUp)    { playerY -= playerSpeed; }
    if (jumping and grounded)   { PlayerVelocityY = -0.2f;}
    playerY += PlayerVelocityY;
}

void Engine::ApplyGravity()
{
    std::max(PlayerVelocityY += gravity, 1.0f);
}
