#include "App.h"
#include "Game.h"
#include "InputHandler.h"
#include "Time.h"

int windowHeight = 600;
int windowWidth = 800;
std::string title = "Breakout";

sf::RenderWindow window;
Game* game;
InputHandler* inputHandler;

int GetWindowHeight()
{
	return window.getSize().y;
}

int GetWindowWidth()
{
	return window.getSize().x;
}

sf::Vector2i GetResolution()
{
	return sf::Vector2i(window.getSize());
}

void Init()
{
	window.create(sf::VideoMode(windowWidth, windowHeight), title, sf::Style::Close);
	inputHandler = new InputHandler();
	game = new Game(window);
}

void Run()
{
	while (window.isOpen())
	{
		window.clear();

		inputHandler->handleInput(window);
		game->Tick();

		window.display();
	}
}

