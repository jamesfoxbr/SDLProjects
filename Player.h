#ifndef PLAYER_H
#define PLAYER_H

#include "Object.h"


class Player: public Object
{
private:

public:
	void SetPosition(float x, float y);
};

#endif // !PLAYER_H
