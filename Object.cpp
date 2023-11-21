#include "Object.h"

Object::Object(float x, float y, std::string path)
	:
	mPosition{x, y}
{
	mSprite = new Sprite(path);
}

Object::~Object()
{
	delete mSprite;
}

void Object::SetPosition(float x, float y)
{
	mPosition.mX = x;
	mPosition.mY = y;
}

Vector2Df Object::GetPosition() const
{
	return mPosition;
}

void Object::Display(float x, float y, SDL_Surface* ScreenSurface)
{
	mSprite->Display(x, y, ScreenSurface);
}


