#include "movement.h"

void Movement::start()
{
	this->m_ptr_ship = s2d::Sprite::getSpriteByName("ship");
}

void Movement::update()
{
	this->moveShip();
}

void Movement::moveShip()
{
	if (s2d::Input::onKeyHold(s2d::KeyBoardCode::A))
	{
		this->m_ptr_ship->transform.position.x -= PLAYER_SPEED * s2d::Time::deltaTime;
	}
	if (s2d::Input::onKeyHold(s2d::KeyBoardCode::D))
	{
		this->m_ptr_ship->transform.position.x += PLAYER_SPEED * s2d::Time::deltaTime;
	}
	
	if (s2d::Input::onKeyHold(s2d::KeyBoardCode::W))
	{
		this->m_ptr_ship->transform.position.y += PLAYER_SPEED * s2d::Time::deltaTime;
	}
	if (s2d::Input::onKeyHold(s2d::KeyBoardCode::S))
	{
		this->m_ptr_ship->transform.position.y -= PLAYER_SPEED * s2d::Time::deltaTime;
	}
}
