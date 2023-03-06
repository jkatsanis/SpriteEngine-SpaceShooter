#pragma once

#include <_header/SpriteEngine.h>

#include "laser.h"
#include "playerController.h"

class Movement : s2d::Base
{
private:
	s2d::Sprite* m_ptr_ship;

	void moveShip();

public:

   void update() override;
   void start() override;
};
