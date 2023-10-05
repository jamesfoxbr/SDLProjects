//#include "Controls.h"
//
//void Controls::Movement	(SDL_Event event)
//{
//    // User Movement
//            // RIGHT
//    if (SDL_KEYDOWN == event.type)
//    {
//        if (SDLK_RIGHT == event.key.keysym.sym)
//            mRight = true;
//    }
//    if (SDL_KEYUP == event.type)
//    {
//        if (SDLK_RIGHT == event.key.keysym.sym)
//            mRight = false;
//    }
//    // LEFT
//    if (SDL_KEYDOWN == event.type)
//    {
//        if (SDLK_LEFT == event.key.keysym.sym)
//            mLeft = true;
//    }
//    if (SDL_KEYUP == event.type)
//    {
//        if (SDLK_LEFT == event.key.keysym.sym)
//            mLeft = false;
//    }
//    // DOWN
//    if (SDL_KEYDOWN == event.type)
//    {
//        if (SDLK_DOWN == event.key.keysym.sym)
//            mDown = true;
//    }
//    if (SDL_KEYUP == event.type)
//    {
//        if (SDLK_DOWN == event.key.keysym.sym)
//            mDown = false;
//    }
//    // UP
//    if (SDL_KEYDOWN == event.type)
//    {
//        if (SDLK_UP == event.key.keysym.sym)
//            mUp = true;
//    }
//    if (SDL_KEYUP == event.type)
//    {
//        if (SDLK_UP == event.key.keysym.sym)
//            mUp = false;
//    }
//}
//
//Controls::Controls()
//    :
//    mPlayerPositionX(10),
//    mPlayerPositionY(10),
//    mPlayerSpeed(0.05f)
//{
//}
//
//void Controls::ApplyKeys()
//{
//    // Apply keypresses
//    if (mLeft == true)  mPlayerPositionX -= mPlayerSpeed;
//    if (mRight == true) mPlayerPositionX += mPlayerSpeed;
//    if (mUp == true)    mPlayerPositionY -= mPlayerSpeed;
//    if (mDown == true)  mPlayerPositionY += mPlayerSpeed;
//}
