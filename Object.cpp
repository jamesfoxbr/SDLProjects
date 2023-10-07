#include "Object.h"

Object::Object(int x, int y, std::string path)
	:
	mPosition{x, y}
{
	mSprite = new Sprite(path);
}

Object::~Object()
{
	delete mSprite;
}

void Object::Position(int x, int y)
{
	mPosition.mX = x;
	mPosition.mY = y;
}

void Object::Display(float x, float y, SDL_Surface* ScreenSurface)
{
	mSprite->Display(x, y, ScreenSurface);
}


