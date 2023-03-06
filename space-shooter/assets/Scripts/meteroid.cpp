#include "meteroid.h"

void Meteroid::start()
{
	this->m_meteroid = std::vector<s2d::Sprite*>(0);
	this->m_spawnCounter = 0.0f;
	this->m_totalSpawned = 0;
}

void Meteroid::update()
{
	this->spawnMeteroids();
	this->moveMeteorid();
	this->deleteMeteroids();
}

void Meteroid::spawnMeteroids()
{
	this->m_spawnCounter += s2d::Time::deltaTime;
	if (this->m_spawnCounter > SPAWN_TIME)
	{
		this->m_totalSpawned++;
		this->m_spawnCounter = 0.0f;
		std::string name = "meteroid " + std::to_string(this->m_totalSpawned);
		s2d::Vector2 pos = s2d::Vector2(s2d::Random::getRandomNumber(-800, 800), 600);
		
		s2d::Sprite* meteroid = new s2d::Sprite(name, pos, "assets\\Sprites\\asteroid.png", true);
		meteroid->collider.exists = true;
		meteroid->collider.boxColliderHeightUpOrDown.x / 2;
		meteroid->collider.boxColliderHeightUpOrDown.y / 2;
		meteroid->collider.boxColliderWidthLeftOrRight.y / 2;
		meteroid->collider.boxColliderWidthLeftOrRight.x / 2;
		meteroid->transform.setScale(s2d::Vector2(0.5, 0.5));
		this->m_meteroid.push_back(meteroid);
	}
}

void Meteroid::moveMeteorid()
{
	for (int i = 0; i < this->m_meteroid.size(); i++)
	{
		this->m_meteroid[i]->transform.position.y -= METEORITE_SPEED * s2d::Time::deltaTime;
	}
}

void Meteroid::deleteMeteroids()
{
	for (int i = 0; i < this->m_meteroid.size(); i++)
	{
		if (this->m_meteroid[i]->collider.isInCollision()
			&& this->m_meteroid[i]->collider.collidingSprite->name == "ship")
		{
			this->m_meteroid[i]->transform.position.y = DELETE_Y_NEGATIVE_COORDINATE;
			this->m_ptr_controller->lifes--;
		}
		else if (this->m_meteroid[i]->collider.isInCollision())
		{
			this->m_meteroid[i]->transform.position.y = DELETE_Y_NEGATIVE_COORDINATE;
		}
	}
	for (int i = 0; i < this->m_meteroid.size(); i++)
	{
		if (this->m_meteroid[i]->transform.position.y < DELETE_Y_NEGATIVE_COORDINATE)
		{
			s2d::Sprite* deleteS = this->m_meteroid[i];
			this->m_meteroid.erase(this->m_meteroid.begin() + i);
			s2d::Sprite::deleteSpriteByName(deleteS->name);
		}
	}

}
