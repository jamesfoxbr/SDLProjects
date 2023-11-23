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

void Player::Display(SDL_Surface* ScreenSurface)
{
	mSprite->Display(mPosition.mX, mPosition.mY, ScreenSurface);
}

void Player::PlayerMovement(const SDL_Event& event)
{

    if (event.type == SDL_KEYDOWN)
    {
        if (event.key.keysym.sym == SDLK_RIGHT) { moveRight = true; }
        if (event.key.keysym.sym == SDLK_LEFT)  { moveLeft = true; }
        if (event.key.keysym.sym == SDLK_DOWN)  { moveDown = true; }
        if (event.key.keysym.sym == SDLK_UP)    { moveUp = true; }
        if (event.key.keysym.sym == SDLK_SPACE && grounded) { jumping = true; }
    }
    if (event.type == SDL_KEYUP)
    {
        if (event.key.keysym.sym == SDLK_RIGHT) { moveRight = false; }
        if (event.key.keysym.sym == SDLK_LEFT)  { moveLeft = false; }
        if (event.key.keysym.sym == SDLK_DOWN)  { moveDown = false; }
        if (event.key.keysym.sym == SDLK_UP)    { moveUp = false; }
        if (event.key.keysym.sym == SDLK_SPACE) { jumping = false; }
    }
}

void Player::AvoidLeaveScreen()
{
    if (mPosition.mX <= 0)                  { mPosition.mX = 0; }
    if (mPosition.mX >= SCREEN_WIDTH - 16)  { mPosition.mX = SCREEN_WIDTH - 16; }
    if (mPosition.mY <= 0)                  { mPosition.mY = 0; }
    if (mPosition.mY >= SCREEN_HEIGHT - 16) { mPosition.mY = SCREEN_HEIGHT - 16; PlayerVelocityY = 0; }
}

void Player::ApplyPlayerMovement()
{
    if (moveRight)              { mPosition.mX += playerSpeed; }
    if (moveLeft)               { mPosition.mX -= playerSpeed; }
    if (moveDown)               { mPosition.mY += playerSpeed; }
    if (moveUp)                 { mPosition.mY -= playerSpeed; }
    if (jumping and grounded)   { PlayerVelocityY = -0.2f; }

    mPosition.mY += PlayerVelocityY;
}

void Player::ApplyGravity()
{
    PlayerVelocityY = std::min(PlayerVelocityY + gravity, 1.0f);
}
