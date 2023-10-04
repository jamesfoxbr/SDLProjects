// ImageLoader.cpp
#include "ImageLoader.h"
#include <SDL_image.h>

ImageLoader::ImageLoader(std::string path) 
{
    mloadedSurface = IMG_Load(path.c_str());
    if (mloadedSurface == nullptr) {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
}

void ImageLoader::display(SDL_Surface* ScreenSurface, float x, float y)
{
    SDL_Rect destRect = {(int)x, (int)y, mloadedSurface->w, mloadedSurface->h};
    SDL_BlitSurface(mloadedSurface, nullptr, ScreenSurface, &destRect);
}
