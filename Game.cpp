#include "Game.h"

Game::Game(SDL_Surface *ScreenSurface, SDL_Window *window)
    :
    mScreenSurface(ScreenSurface),
    mWindow(window)
{
    GameLoop();
}

void Game::GameLoop()
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
        Update(event);

        //Fill surface with color
        SDL_FillRect(mScreenSurface, NULL, SDL_MapRGB(mScreenSurface->format, 0x88, 0x88, 0x88));

        Draw();

        //Update the surface
        SDL_UpdateWindowSurface(mWindow);
    }
}

void Game::Start()
{
}

void Game::Update(SDL_Event event)
{
    // Checks if the character is grounded
    if (james.GetPosition().mY >= SCREEN_HEIGHT - 16) { james.SetGrounded(true); }
    else { james.SetGrounded(false); }

    james.AvoidLeaveScreen();
    james.ApplyPlayerMovement();
    james.ApplyGravity();
}

void Game::Draw()
{
    //Called every frame

    james.Display(mScreenSurface);
}