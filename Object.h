#ifndef OBJECT_H
#define OBJECT_H

#include "Vector2D.h"
#include "Sprite.h"
#include <string>

class Object
{
private:
	Vector2Di mPosition{0,0};
public:
	Object(int x, int y, std::string path);
	Object() = default;
	void Position(int x, int y);
};

#endif // !OBJECT_H