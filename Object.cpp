#include "Object.h"

Object::Object(int x, int y)
	:
	mPosition{x, y}
{
	
}

void Object::GetPosition(int x, int y)
{
	mPosition.mX = x;
	mPosition.mY = y;
}
