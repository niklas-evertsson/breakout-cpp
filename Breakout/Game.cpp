#include "Ball.h"
#include "Game.h"

Game::Game(sf::RenderWindow &window) : window(window)
{
	AddActor(new Ball());
}

float Game::DeltaTime()
{
	return deltaClock.restart().asSeconds();
}

float Game::ElapsedTime()
{
	return elapsedClock.getElapsedTime().asSeconds();
}

void Game::AddActor(Actor* actor)
{
	actors.push_back(actor);
}

void Game::CheckCollision(Actor* actor1, Actor* actor2)
{
}

void Game::Draw(Actor* actor)
{
	window.draw(*(actor)->GetSprite());
}

void Game::Tick()
{
	deltaTime = DeltaTime();
	elapsedTime = ElapsedTime();

	std::vector<Actor*>::iterator a1;
	std::vector<Actor*>::iterator a2;
	for(a1 = actors.begin(); a1 != actors.end(); a1++)
	{
		Update(*a1);
		Draw(*a1);

		for(a2 = actors.begin(); a2 < a1; a2++)
		{
			CheckCollision(*a1, *a2);
		}
	}
}

void Game::Update(Actor* actor)
{
	actor->Update(deltaTime);
}
