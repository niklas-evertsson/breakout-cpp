#pragma once
#include "Command.h"

class InputHandler
{
public:
	InputHandler();
	static sf::Vector2f mousePosition;
	Command* HandleInput(sf::Window& window);

private:
	Command* pause = 0;
	Command* start = 0;
	Command* mouseX = 0;
};

