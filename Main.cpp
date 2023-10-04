// Main.cpp
#include <stdio.h>
#include <string>
#include "Main.h"
#include "ImageLoader.h" // Include the new header
#include "Controls.h"

// Declare SDL_Window and SDL_Surface pointers
SDL_Window* gWindow = nullptr;
SDL_Surface* gScreenSurface = nullptr;
SDL_Surface* gPNGSurface = nullptr;

int main(int argc, char* args[])
{

    // Create user control
    Controls controls;

    // Create image object
    ImageLoader jaminho("images/Idle.png");
    ImageLoader ball("images/Ball.png");

    // Start up SDL and create window
    if (!init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        
        // Main game loop flag
        bool quit = false;

        // Event handler
        SDL_Event event;

        // Main game loop
        while (!quit)
        {
            //Handle events on queue
            while (SDL_PollEvent(&event) != 0)
            {
                //User requests quit
                if (event.type == SDL_QUIT)
                {
                    quit = true;
                }
                // User Movement
                controls.Movement(event);
            }

            // Apply user keypresses
            controls.ApplyKeys();

            // Clear the screen with a gray background (RGB values for gray)
            SDL_FillRect(gScreenSurface, nullptr, SDL_MapRGB(gScreenSurface->format, 128, 128, 128));

            // Display the PNG images
            jaminho.display(gScreenSurface, controls.GetX(), controls.GetY());
            for (int i = 0; i < 10; i++)
            {
                ball.display(gScreenSurface, rand()%100 + (i * 8), rand() % 100 + (i * 8));
            }

            // Update the surface
            SDL_UpdateWindowSurface(gWindow);
        }
    }

    // Free resources and close SDL
    close();

    return 0;
}

bool init()
{
    // Initialization flag
    bool success = true;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        // Create window
        gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == nullptr)
        {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            // Get window surface
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }

    return success;
}

void close()
{
    // Free loaded image
    SDL_FreeSurface(gPNGSurface);
    gPNGSurface = nullptr;

    // Destroy window
    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;

    // Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}
