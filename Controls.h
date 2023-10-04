#ifndef CONTROLS_H
#define CONTROLS_H

#include "Main.h"

class Controls
{
private:
    float m_playerPositionX;
    float m_playerPositionY;
    float m_playerSpeed;

    // Detect Keypress
    bool m_up = false;
    bool m_down = false;
    bool m_left = false;
    bool m_right = false;
public:
    Controls()
        :
        m_playerPositionX(10),
        m_playerPositionY(10),
        m_playerSpeed(0.05)
    {

    }
    void Movement(SDL_Event event);
    void ApplyKeys();
    float GetX() 
    {
        return m_playerPositionX;
    }
    float GetY()
    {
        return m_playerPositionY;
    }
};

#endif // !CONTROLS_H

