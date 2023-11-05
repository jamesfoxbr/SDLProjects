#ifndef CONTROLS_H
#define CONTROLS_H

#include "Main.h"

class Controls
{
private:
    // Detect Keypress
    bool mUp = false;
    bool mDown = false;
    bool mLeft = false;
    bool mRight = false;
public:
    void Movement(SDL_Event event);
    //void ApplyKeys();
};

#endif // !CONTROLS_H

