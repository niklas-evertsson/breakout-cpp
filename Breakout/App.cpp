#include "App.h"
#include "Game.h"
#include "InputHandler.h"

namespace App
{
	std::map<ActorType, std::string> texturePath
	{
		{ ActorType::Ball, "../resources/ball32.png" },
		{ ActorType::Brick, "../resources/brick64x32.png" },
		{ ActorType::Paddle, "../resources/paddle128x32.png" },
	};

	int windowWidth = 1024;
	int windowHeight = 1024;
	std::string levelPath = "../resources/level.csv";
	std::string title = "Breakout";

	sf::RenderWindow window;
	Game game(window);
	InputHandler inputHandler;
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

std::string App::GetLevelPath()
{
	return levelPath;
}

void App::Init()
{
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	window.create(sf::VideoMode(windowWidth, windowHeight, desktop.bitsPerPixel), title, sf::Style::Close);
	game.Init();
}

void App::Run()
{
	while (window.isOpen())
	{
		window.clear();

		Command* command = inputHandler.HandleInput(window);
		game.ExecuteCommand(command);
		game.Tick();

		window.display();
	}
}
