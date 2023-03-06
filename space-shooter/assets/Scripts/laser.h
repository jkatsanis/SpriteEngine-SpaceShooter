#pragma once

#include <_header/SpriteEngine.h>
#include <movement.h>

#define DELETE_Y_POSITIVE_COORDINATE 600
#define DELETE_Y_NEGATIVE_COORDINATE -600

#define SHOOT_DELAY 0.5f

class Laser : s2d::Base
{
private:
	std::vector<s2d::Sprite*> m_lasers;
	const s2d::Sprite* m_ptr_SHIP;
    float m_shootDelay;
	short m_lifes;

	void moveLaser();
	void shoot();
	void deleteLaser();
public:

   void update() override;
   void start() override;
};
