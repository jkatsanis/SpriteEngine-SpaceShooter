#include "game.h"

void Game::start()
{
	this->m_controller = PlayerController();
	this->m_metorid.start();
	this->m_movement.start();
	this->m_laser.start();
	this->m_ui.start();

	this->m_metorid.setController(&this->m_controller);
}

void Game::update()
{
	this->m_ui.update(this->m_controller);
	this->m_metorid.update();
	this->m_movement.update();
	this->m_laser.update();
}
