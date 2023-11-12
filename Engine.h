#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <SDL.h>
#include <vector>
#include "Window.h"
#include "Object.h"

class Engine
{
private:

	SDL_Window* mWindow = nullptr;           //The window we'll be rendering to
	SDL_Surface* mScreenSurface = nullptr;	 //The surface contained by the window

	float playerX     = 50.0f;
	float playerY     = 50.0f;
	float playerVelocityX = 0.0f;
	float PlayerVelocityY = 0.0f;
	float playerSpeed = 0.05f;

	bool moveRight = false;
	bool moveLeft  = false;
	bool moveDown  = false;
	bool moveUp    = false;

	bool jumping   = false;

	float gravity  = 0.0001f;
	bool grounded = false;

public:
	// Player variables
	Object james{playerX, playerY, "images/Idle.png"};
	

	// Detect Keypress
	/*bool mUp = false;
	bool mDown = false;
	bool mLeft = false;
	bool mRight = false;*/

	Engine();
	~Engine();

	void GameLoop();
	void Start();
	void Update();
	void Draw();

	SDL_Surface GetSurface();

	void PlayerMovement(const SDL_Event& e);
	void AvoidLeaveScreen();
	void ApplyPlayerMovement();
	void ApplyGravity();
};

#endif // !ENGINE_H
