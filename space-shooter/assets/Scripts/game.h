#pragma once

#include <_header/SpriteEngine.h>

#include "laser.h"
#include "movement.h"
#include "meteroid.h"
#include "ui.h"
#include "playerController.h"

class Game : s2d::Base
{
private:
	Laser m_laser;
	Movement m_movement;
	Meteroid m_metorid;
	UI m_ui;
	PlayerController m_controller;

public:
	void update() override;
	void start() override;
};
