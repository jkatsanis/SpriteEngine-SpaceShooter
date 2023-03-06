#pragma once

#include <_header/SpriteEngine.h>

#include "playerController.h"

class UI : public s2d::Base
{
public:
	void update(const PlayerController& controller);

};

