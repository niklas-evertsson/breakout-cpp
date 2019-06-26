#include "Ball.h"
#include "Game.h"

Game::Game()
{
	AddActor(new Ball());
}

void Game::AddActor(Actor* actor)
{
	actors.push_back(actor);
}

void Game::Draw(sf::RenderWindow &window)
{
	std::list<Actor*>::iterator	it;
	for(it = actors.begin(); it != actors.end(); it++)
	{
		window.draw(*((*it)->GetSprite()));
	}
}

void Game::Update(float deltaTime)
{
	std::list<Actor*>::iterator	it;
	for(it = actors.begin(); it != actors.end(); it++)
	{
		(*it)->Update(deltaTime);
	}
}
