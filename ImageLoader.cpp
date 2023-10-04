// ImageLoader.cpp
#include "ImageLoader.h"
#include <SDL_image.h>

SDL_Surface* ImageLoader::load(std::string path) {
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr) {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    return loadedSurface;
}
