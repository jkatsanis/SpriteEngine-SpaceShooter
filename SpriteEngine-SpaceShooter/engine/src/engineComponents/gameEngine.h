#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <engineComponents/input.h>
#include <engineComponents/sTime.h>
#include <data/FileData.h>
#include <calculationComponents/physics.h>
#include <imgui.h>
#include <imgui-SFML.h>
#include <manager/GUIManager.h>
#include <engineComponents/renderer.h>

//All user files
#include "movement.h"
#include "laser.h"
#include "meteroid.h"

namespace s2d
{
    class GameEngine
	{
		//User classes, only 1 instance
		Movement movement;
		Laser laser;
		Meteroid meteroid;

		s2d::Renderer m_renderer;

		float m_timePassed;
		bool m_isWindowFullScreen;

		void pollEngineEvents();
		void pollEvents();
		void updateUserScriptsAndGUI();
		void updateWindowStyle();

	public:
		s2d::Event event;
		sf::Event windowEvent;
		sf::RenderWindow* ptr_renderWindow;

		GameEngine();
		~GameEngine();

		void update();
		void start();
		bool isGameRunning();
	};
}

