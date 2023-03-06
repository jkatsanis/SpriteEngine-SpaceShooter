#include "ui.h"

void UI::update(const PlayerController& controller)
{
	std::string lifes = "Lifes: " + std::to_string(controller.lifes);
	ImGui::Text(lifes.c_str());
	std::string fps = "FPS: " + std::to_string(s2d::Time::fps);
	ImGui::Text(fps.c_str());
}
