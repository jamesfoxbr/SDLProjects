#ifndef OBJECT_H
#define OBJECT_H

#include "Vector2D.h"
#include <string>

class Object
{
private:
	Vector2Di mPosition{0,0};
public:
	Object(int x, int y);
	Object() = default;
	void GetPosition(int x, int y);
};

#endif // !OBJECT_H

