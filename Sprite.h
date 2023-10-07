#ifndef Sprite_H
#define Sprite_H

#include <string>
#include <SDL.h>
#include <SDL_image.h>

class Sprite {
private:
    SDL_Surface* mPNGSurface    = nullptr;
    SDL_Surface* mloadedSurface = nullptr;
public:
    Sprite(std::string path);
    Sprite() = default;
    ~Sprite();
    void Display(float x, float y, SDL_Surface* ScreenSurface);
    SDL_Surface GetLoadedSurface();

};

#endif // !Sprite_H

