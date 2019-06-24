#include <SFML/Graphics.hpp>
#include "InputHandler.h"

void InputHandler::handleInput(sf::Window &window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::GainedFocus:
			// TODO: Unpause game
			break;
		case sf::Event::KeyPressed:
			switch (event.key.code)
			{
			case sf::Keyboard::Space:
				// TODO: Start game
				break;
			default:
				break;
			}
		case sf::Event::LostFocus:
			// TODO: Pause game
			break;
		default:
			break;
		}
	}
}
