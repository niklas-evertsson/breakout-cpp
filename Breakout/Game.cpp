#include "App.h"
#include "Ball.h"
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow &window) : window(window)
{
	LoadTextures();
	Actor* ball = new Ball(&textures[ActorType::Ball], ActorType::Ball);
	AddActor(ball);
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
	actor->Init();
	actors.push_back(actor);
}

void Game::CheckCollision(Actor* actor1, Actor* actor2)
{
	sf::FloatRect box1 = actor1->GetGlobalBounds();
	sf::FloatRect box2 = actor2->GetGlobalBounds();

	if (box1.intersects(box2))
	{
		actor1->OnCollision(actor2);
		actor2->OnCollision(actor1);
	}
}

void Game::Draw(Actor* actor)
{
	window.draw(*(actor)->GetSprite());
}

void Game::LoadTextures()
{
	std::map<ActorType, std::string>::iterator it;
	for(it = App::texturePath.begin(); it != App::texturePath.end(); it++)
	{
		sf::Texture texture;
		std::string texturePath = it->second;
		if (!texture.loadFromFile(texturePath))
		{
			continue;
		}
		textures.insert(std::make_pair(ActorType::Ball, texture));
	}

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
