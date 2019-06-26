#include "App.h"
#include "Game.h"
#include "InputHandler.h"
#include "Time.h"

float deltaTime = 0.0f;
float elapsedTime = 0.0f;
int windowHeight = 600;
int windowWidth = 800;
std::string title = "Breakout";

sf::Clock deltaClock;
sf::Clock elapsedClock;
sf::RenderWindow window;
Game* game;
InputHandler* inputHandler;

float DeltaTime()
{
	return deltaClock.restart().asSeconds();
}

float ElapsedTime()
{
	return elapsedClock.getElapsedTime().asSeconds();
}

int GetWindowHeight()
{
	return window.getSize().y;
}

int GetWindowWidth()
{
	return window.getSize().x;
}

void Tick()
{
	deltaTime = deltaClock.restart().asSeconds();
	elapsedTime = elapsedClock.getElapsedTime().asSeconds();
}

sf::Vector2i GetResolution()
{
	return sf::Vector2i(window.getSize());
}

void Init()
{
	window.create(sf::VideoMode(windowWidth, windowHeight), title, sf::Style::Close);
	inputHandler = new InputHandler();
	game = new Game();
}

void Run()
{
	while (window.isOpen())
	{
		Tick();
		window.clear();

		inputHandler->handleInput(window);
		game->Update(deltaTime);
		game->Draw(window);

		window.display();
	}
}

