#include <SFML/Graphics.hpp>
#include "InputHandler.h"

InputHandler::InputHandler()
{
	mouseX = new MoveXCommand(this);
}

sf::Vector2f InputHandler::mousePosition;

Command* InputHandler::HandleInput(sf::Window &window)
{
	mousePosition = (sf::Vector2f)sf::Mouse::getPosition(window);

	sf::Event event;
	Command* command = NULL;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::GainedFocus:
			command = start;
			break;
		case sf::Event::KeyPressed:
			switch (event.key.code)
			{
			case sf::Keyboard::Space:
				command = start;
				break;
			default:
				break;
			}
		case sf::Event::LostFocus:
			command = pause;
			break;
		default:
			command = mouseX;
			break;
		}
	}
	return command;
}
