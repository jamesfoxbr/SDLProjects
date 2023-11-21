#include "Player.h"

void Player::SetPosition(float x, float y)
{
	mPosition.mX = x;
	mPosition.mY = y;
}

Player::Player(float x, float y, std::string path)
{
	mSprite = new Sprite(path);
}

void Player::Display(float x, float y, SDL_Surface* ScreenSurface)
{
	mSprite->Display(x, y, ScreenSurface);
}
