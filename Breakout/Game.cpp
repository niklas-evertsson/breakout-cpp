#include "Game.h"

Game::Game(int sizeX, int sizeY):
	sizeX(sizeX),
	sizeY(sizeY)
{}

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

void Game::Update()
{
	std::list<Actor*>::iterator	it;
	for(it = actors.begin(); it != actors.end(); it++)
	{
		(*it)->Update();
	}
}