#pragma once

#include <_header/SpriteEngine.h>

#include "laser.h"

class Movement : s2d::Base
{
private:
	s2d::Sprite* m_ptr_ship;

	void moveShip();

public:
	const static float SPEED;

   void update() override;
   void start() override;
};
