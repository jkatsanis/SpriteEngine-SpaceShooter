#pragma once

#include <_header/SpriteEngine.h>
#include <calculationComponents/srandom.h>
#include "movement.h"

#define SPAWN_TIME 1

class Meteroid : s2d::Base
{
private:
	std::vector<s2d::Sprite*> m_meteroid;
	float m_spawnCounter;

	void spawnMeteroids();
	void moveMeteorid();
	void deleteMeteroids();
public:

	void update() override;
	void start() override;
};
