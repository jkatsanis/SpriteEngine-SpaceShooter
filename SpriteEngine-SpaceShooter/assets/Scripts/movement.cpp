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
		this->m_ptr_ship->transform.position.x -= Movement::SPEED * s2d::Time::deltaTime;
	}
	if (s2d::Input::onKeyHold(s2d::KeyBoardCode::D))
	{
		this->m_ptr_ship->transform.position.x += Movement::SPEED * s2d::Time::deltaTime;
	}
	//if (s2d::Input::onKeyHold(s2d::KeyBoardCode::W))
	//{
	//	this->m_ptr_ship->transform.position.y += Movement::SPEED * s2d::Time::deltaTime;
	//}
	//if (s2d::Input::onKeyHold(s2d::KeyBoardCode::S))
	//{
	//	this->m_ptr_ship->transform.position.y -= Movement::SPEED * s2d::Time::deltaTime;
	//}
	//if (s2d::Input::onKeyHold(s2d::KeyBoardCode::C))
	//{
	//	s2d::Sprite* scaled = s2d::Sprite::getSpriteByName("Sprite 3 id: 6");
	//	scaled->transform.setScale(s2d::Vector2(5, 1));
	//}
}

const float Movement::SPEED = 800;