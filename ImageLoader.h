// ImageLoader.h
#pragma once

#include <string>
#include <SDL.h>

class ImageLoader {
public:
    static SDL_Surface* load(std::string path);
};
