#pragma once

#define LIFES 3
#define PLAYER_SPEED 800.0f

class PlayerController
{
public:
	short lifes;

	PlayerController()
		: lifes(LIFES) { }
};