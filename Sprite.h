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
    void display(SDL_Surface* ScreenSurface, float x, float y);

};

#endif // !Sprite_H

