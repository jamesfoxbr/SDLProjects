// Main.cpp
#include <stdio.h>
#include <string>
#include "Main.h"
#include "ImageLoader.h" // Include the new header

// Declare SDL_Window and SDL_Surface pointers
SDL_Window* gWindow = nullptr;
SDL_Surface* gScreenSurface = nullptr;
SDL_Surface* gPNGSurface = nullptr;

int main(int argc, char* args[])
{
    float playerPositionX = 10;
    float playerPositionY = 10;
    float playerSpeed = 0.05;

    // Detect Keypress
    bool up = false;
    bool down = false;
    bool left = false;
    bool right = false;

    // Start up SDL and create window
    if (!init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        // Load media
        if (!loadMedia())
        {
            printf("Failed to load media!\n");
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
                    // RIGHT
                    if (SDL_KEYDOWN == event.type)
                    {
                        if (SDLK_RIGHT == event.key.keysym.sym)
                            right = true;
                    }
                    if (SDL_KEYUP == event.type)
                    {
                        if (SDLK_RIGHT == event.key.keysym.sym)
                            right = false;
                    }
                    // LEFT
                    if (SDL_KEYDOWN == event.type)
                    {
                        if (SDLK_LEFT == event.key.keysym.sym)
                            left = true;
                    }
                    if (SDL_KEYUP == event.type)
                    {
                        if (SDLK_LEFT == event.key.keysym.sym)
                            left = false;
                    }
                }

                // Apply keypresses
                if (left  == true) playerPositionX -= playerSpeed;
                if (right == true) playerPositionX += playerSpeed;
                if (up    == true) playerPositionY -= playerSpeed;
                if (down  == true) playerPositionY += playerSpeed;

                // Clear the screen with a gray background (RGB values for gray)
                SDL_FillRect(gScreenSurface, nullptr, SDL_MapRGB(gScreenSurface->format, 128, 128, 128));

                // Apply the PNG image
                SDL_Rect destRect = {playerPositionX, playerPositionY, gPNGSurface->w, gPNGSurface->h};
                SDL_BlitSurface(gPNGSurface, nullptr, gScreenSurface, &destRect);

                // Update the surface
                SDL_UpdateWindowSurface(gWindow);

            }
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

bool loadMedia()
{
    // Loading success flag
    bool success = true;

    // Load PNG surface using the ImageLoader class
    gPNGSurface = ImageLoader::load("images/Idle.png");
    if (gPNGSurface == nullptr)
    {
        printf("Failed to load PNG image!\n");
        success = false;
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
