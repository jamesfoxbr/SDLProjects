#ifndef OBJECT_H
#define OBJECT_H

#include "Vector2D.h"
#include "Sprite.h"
#include <string>

class Object
{
protected:
	float     mSpeed = 0;
	Vector2Di mPosition{0,0};
	Sprite*   mSprite = nullptr;
private:
	
public:
	Object(int x, int y, std::string path);
	Object() = default;
	~Object();
	void SetPosition(int x, int y);
	Vector2Di GetPosition();
	void Display(float x, float y, SDL_Surface* ScreenSurface);
};

#endif // !OBJECT_H