#ifndef PLAYER_H
#define PLAYER_H

#include <algorithm>
#include "Object.h"
#include "Window.h"


class Player: public Object
{
private:
	float playerVelocityX       = 0.0f;        // player x current velocity
	float PlayerVelocityY       = 0.0f;        // player y current velocity
	float playerSpeed           = 0.05f;
	const float horizontalAccel = 0.00005f;
	const float maxAccel        = 0.05f;

	bool moveRight = false;
	bool moveLeft  = false;
	bool moveDown  = false;
	bool moveUp    = false;

	bool jumping   = false;

	float gravity  = 0.0001f;
	bool  grounded = false;

public:
	void SetPosition(float x, float y);
	Player(float x, float y, std::string path);
	void Display(SDL_Surface* ScreenSurface);

	void PlayerMovement(const SDL_Event& e);
	void AvoidLeaveScreen();
	void ApplyPlayerMovement();
	void ApplyGravity();
	void SetGrounded(bool a) { grounded = a; }
};

#endif // !PLAYER_H
