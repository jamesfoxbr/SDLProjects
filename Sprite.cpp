#include "Sprite.h"
#include <SDL_image.h>

Sprite::Sprite(std::string path)
{
    mloadedSurface = IMG_Load(path.c_str());
    if (mloadedSurface == nullptr) {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
}


Sprite::~Sprite()
{
    // Free loaded image
    SDL_FreeSurface(mPNGSurface);
    mPNGSurface = nullptr;
}

void Sprite::Display(float x, float y, SDL_Surface* ScreenSurface)
{
    SDL_Rect destRect = {(int)x, (int)y, mloadedSurface->w, mloadedSurface->h};
    SDL_BlitSurface(mloadedSurface, nullptr, ScreenSurface, &destRect);
}

SDL_Surface Sprite::GetLoadedSurface()
{
    return *mloadedSurface;
}
