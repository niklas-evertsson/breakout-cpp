#include "App.h"
#include "Game.h"
#include "InputHandler.h"

namespace App
{
	std::map<ActorType, std::string> texturePath
	{
		{ ActorType::Ball, "../resources/ball32.png" },
		{ ActorType::Brick, "" },
		{ ActorType::Paddle, "" },
	};

	int windowHeight = 640;
	int windowWidth = 800;
	std::string title = "Breakout";

	sf::RenderWindow window;
	Game* game;
	InputHandler* inputHandler;
}

int App::GetWindowHeight()
{
	return window.getSize().y;
}

int App::GetWindowWidth()
{
	return window.getSize().x;
}

sf::Vector2i App::GetResolution()
{
	return sf::Vector2i(window.getSize());
}

void App::Init()
{
	window.create(sf::VideoMode(windowWidth, windowHeight), title, sf::Style::Close);
	inputHandler = new InputHandler();
	game = new Game(window);
}

void App::Run()
{
	while (window.isOpen())
	{
		window.clear();

		inputHandler->handleInput(window);
		game->Tick();

		window.display();
	}
}
