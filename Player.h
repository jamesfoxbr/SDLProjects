#ifndef PLAYER_H
#define PLAYER_H

#include "Object.h"


class Player: public Object
{
private:

public:
	void SetPosition(float x, float y);
	Player(float x, float y, std::string path);
	void Display(float x, float y, SDL_Surface* ScreenSurface);
};

#endif // !PLAYER_H
