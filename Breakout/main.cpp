#include <SFML/Graphics.hpp>
#include "Game.h"
#include "InputHandler.h"

int main()
{
	int windowHeight = 600;
	int windowWidth = 800;

	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Breakout", sf::Style::Close);
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	InputHandler* inputHandler = new InputHandler();
	Game* game = new Game(windowWidth, windowHeight);

	while (window.isOpen())
	{
		window.clear();

		inputHandler->handleInput(window);
		game->Update();
		game->Draw(window);

		window.display();
	}

	return EXIT_SUCCESS;
}