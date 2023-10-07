#ifndef OBJECT_H
#define OBJECT_H

#include "Vector2D.h"
#include "Sprite.h"
#include <string>

class Object
{
private:
	Vector2Di mPosition{0,0};
	Sprite* mSprite = nullptr;
public:
	Object(int x, int y, std::string path);
	Object() = default;
	~Object();
	void Position(int x, int y);
	void Display(float x, float y, SDL_Surface* ScreenSurface);
};

#endif // !OBJECT_H