#include "Controls.h"

void Controls::Movement	(SDL_Event event)
{
    // User Movement
            // RIGHT
    if (SDL_KEYDOWN == event.type)
    {
        if (SDLK_RIGHT == event.key.keysym.sym)
            m_right = true;
    }
    if (SDL_KEYUP == event.type)
    {
        if (SDLK_RIGHT == event.key.keysym.sym)
            m_right = false;
    }
    // LEFT
    if (SDL_KEYDOWN == event.type)
    {
        if (SDLK_LEFT == event.key.keysym.sym)
            m_left = true;
    }
    if (SDL_KEYUP == event.type)
    {
        if (SDLK_LEFT == event.key.keysym.sym)
            m_left = false;
    }
    // DOWN
    if (SDL_KEYDOWN == event.type)
    {
        if (SDLK_DOWN == event.key.keysym.sym)
            m_down = true;
    }
    if (SDL_KEYUP == event.type)
    {
        if (SDLK_DOWN == event.key.keysym.sym)
            m_down = false;
    }
    // UP
    if (SDL_KEYDOWN == event.type)
    {
        if (SDLK_UP == event.key.keysym.sym)
            m_up = true;
    }
    if (SDL_KEYUP == event.type)
    {
        if (SDLK_UP == event.key.keysym.sym)
            m_up = false;
    }
}

void Controls::ApplyKeys()
{
    // Apply keypresses
    if (m_left == true)  m_playerPositionX -= m_playerSpeed;
    if (m_right == true) m_playerPositionX += m_playerSpeed;
    if (m_up == true)    m_playerPositionY -= m_playerSpeed;
    if (m_down == true)  m_playerPositionY += m_playerSpeed;
}
