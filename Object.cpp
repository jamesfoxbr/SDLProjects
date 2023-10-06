#include "Object.h"

Object::Object(int x, int y, std::string path)
	:
	mPosition{x, y}
{

}

void Object::Position(int x, int y)
{
	mPosition.mX = x;
	mPosition.mY = y;
}
