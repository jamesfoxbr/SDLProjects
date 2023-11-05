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

void Object::SetPosition(int x, int y)
{
	mPosition.mX = x;
	mPosition.mY = y;
}

Vector2Di Object::GetPosition()
{
	return mPosition;
}

void Object::Display(float x, float y, SDL_Surface* ScreenSurface)
{
	mSprite->Display(x, y, ScreenSurface);
}


