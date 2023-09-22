#include "Game.h"
#include <iostream>

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
    // attempt to initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL init success\n";
        // init the window
        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (m_pWindow != 0) // window init success
        {
            std::cout << "window creation success\n";
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
            if (m_pRenderer != 0) // renderer init success
            {
                std::cout << "renderer creation success\n";
                SDL_SetRenderDrawColor(m_pRenderer, 100, 100, 100, 255);

                // loading BMP image
                SDL_Surface* pTempSurface = SDL_LoadBMP("images/idle.bmp");
                m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
                SDL_FreeSurface(pTempSurface);
                SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);
                m_destinationRectangle.x = 100;                 // position X
                m_sourceRectangle.x = 0;
                m_destinationRectangle.y = 100;                 // position Y
                m_sourceRectangle.y = 0;
                m_sourceRectangle.w = 128;                      // texture width
                m_sourceRectangle.h = 128;                      // texture height
                m_destinationRectangle.w = m_sourceRectangle.w;
                m_destinationRectangle.h = m_sourceRectangle.h;
            }
            else
            {
                std::cout << "renderer init fail\n";
                return false; // renderer init fail
            }
        }
        else
        {
            std::cout << "window init fail\n";
            return false; // window init fail
        }
    }
    else
    {
        std::cout << "SDL init fail\n";
        return false; // SDL init fail
    }

    
    std::cout << "init success\n";
    m_bRunning = true; // everything inited successfully, start the main loop
    
    return true;
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer);       // clear the renderer to the draw color
    SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
    SDL_RenderPresent(m_pRenderer);     // draw to the screen
}

void Game::update()
{

}

void Game::handleEvents()
{
    SDL_Event event;
    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            m_bRunning = false;
            break;
        default:
            break;
        }
    }
}

void Game::clean()
{
    std::cout << "cleaning game\n";
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    IMG_Quit();
    SDL_Quit();
}