#ifndef ENGINE_H
#define ENGINE_H

#include <stdio.h>
#include <SDL.h>
#include "Window.h"

class Engine
{
private:
	void GameLoop();
	void Start();
	void Update();
	void Draw();

public:
	Engine();
	~Engine();
};

#endif // !ENGINE_H
