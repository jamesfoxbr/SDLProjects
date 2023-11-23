#ifndef _GAME_H
#define _GAME_H

#include <SDL.h>
#include "Player.h"
#include "Window.h"
#include "Timer.h"

class Game
{
private:
	SDL_Surface * mScreenSurface = nullptr;
	SDL_Window* mWindow = nullptr;
	Player james{50, 50, "images/Idle.png"};

public:
	Game(SDL_Surface *ScreenSurface, SDL_Window *window);
	void GameLoop();
	void Start();
	void Update(SDL_Event event);
	void Draw();
};

#endif // !_GAME_H

