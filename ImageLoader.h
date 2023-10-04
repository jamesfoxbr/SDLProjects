// ImageLoader.h
#pragma once

#include <string>
#include <SDL.h>

class ImageLoader {
private:
    SDL_Surface* mPNGSurface    = nullptr;
    SDL_Surface* mloadedSurface = nullptr;
public:
    SDL_Surface* load(std::string path);
    void display(SDL_Surface* ScreenSurface, float x, float y);

};
