#pragma once

#include <_header/SpriteEngine.h>
#include <calculationComponents/srandom.h>
#include "playerController.h"
#include "laser.h"

#define SPAWN_TIME 1.0f 
#define METEORITE_SPEED 400

class Meteroid : s2d::Base
{
private:
	std::vector<s2d::Sprite*> m_meteroid;
	float m_spawnCounter;
	PlayerController* m_ptr_controller;
	int m_totalSpawned;

	void spawnMeteroids();
	void moveMeteorid();
	void deleteMeteroids();

public:
	void update() override;
	void start() override;

	void setController(PlayerController* controller) { this->m_ptr_controller = controller; }
};
