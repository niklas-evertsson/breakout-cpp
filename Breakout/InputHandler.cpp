#include "InputHandler.h"
#include <SFML/Graphics.hpp>

InputHandler::InputHandler()
{
	mouseX = new MoveXCommand(this);
	start = new StartCommand(this);
}

sf::Vector2f InputHandler::mousePosition;

Command* InputHandler::HandleInput(sf::Window &window)
{
	mousePosition = (sf::Vector2f)sf::Mouse::getPosition(window);

	sf::Event event;
	Command* command = NULL;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
		else if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Space)
			{
				return start;
			}
		}
	}
	return mouseX;
}
