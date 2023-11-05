#ifndef OBJECT_H
#define OBJECT_H

#include "Vector2D.h"
#include "Sprite.h"
#include <string>

class Object
{
protected:
	float     mSpeed = 0;
	Vector2Df mPosition{0,0};
	Sprite*   mSprite = nullptr;
private:
	
public:
	Object(float x, float y, std::string path);
	Object() = default;
	~Object();
	void SetPosition(float x, float y);
	Vector2Df GetPosition();
	void Display(float x, float y, SDL_Surface* ScreenSurface);
};

#endif // !OBJECT_H