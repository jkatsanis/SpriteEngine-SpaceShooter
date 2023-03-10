#include "laser.h"


void Laser::start()
{
	this->m_ptr_SHIP = s2d::Sprite::getSpriteByName("ship");
	this->m_lasers = std::vector<s2d::Sprite*>(0);
	this->m_shootDelay = 0.0f;
}

void Laser::update()
{
	this->deleteLaser();
	this->moveLaser();
	this->shoot();
}

void Laser::moveLaser()
{
	for (int i = 0; i < this->m_lasers.size(); i++)
	{
		this->m_lasers[i]->transform.position.y += PLAYER_SPEED * s2d::Time::deltaTime;
	}
}

void Laser::shoot()
{	
	this->m_shootDelay += s2d::Time::deltaTime;

	if (s2d::Input::onKeyPress(s2d::KeyBoardCode::Space) && this->m_shootDelay > SHOOT_DELAY)
	{
		this->m_shootDelay = 0.0f;

		std::string name = "laser " + std::to_string(this->m_lasers.size());
		s2d::Vector2 pos = s2d::Vector2(this->m_ptr_SHIP->transform.position.x, this->m_ptr_SHIP->transform.position.y
			+ this->m_ptr_SHIP->transform.textureSize.y / 2);
		s2d::Sprite* laser = new s2d::Sprite(name, pos, "assets\\Sprites\\laser.png", true);
		laser->transform.setScale(s2d::Vector2(0.5, 0.5));
		laser->collider.exists = true;
		this->m_lasers.push_back(laser);
	}
}

void Laser::deleteLaser()
{
	for (int i = 0; i < this->m_lasers.size(); i++)
	{
		if (this->m_lasers[i]->transform.position.y > DELETE_Y_POSITIVE_COORDINATE)
		{
			s2d::Sprite* deleteS = this->m_lasers[i];
			this->m_lasers.erase(this->m_lasers.begin() + i);
  			s2d::Sprite::deleteSpriteByName(deleteS->name);
		}
	}
}


