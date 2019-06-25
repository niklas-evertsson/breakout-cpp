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

void Tick()
{
	deltaTime = deltaClock.restart().asSeconds();
	elapsedTime = elapsedClock.getElapsedTime().asSeconds();
}

sf::RenderWindow* GetWindow()
{
	return &window;
}

sf::Vector2i GetResolution()
{
	return sf::Vector2i(sf::VideoMode().width, sf::VideoMode().height);
}

void Init()
{
	game = new Game(windowWidth, windowHeight);
	inputHandler = new InputHandler();
	window.create(sf::VideoMode(windowWidth, windowHeight), title, sf::Style::Close);
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

