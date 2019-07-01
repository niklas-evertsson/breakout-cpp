#include "Brick.h"
#include "Game.h"
#include <iostream>

Brick::Brick() : Actor(ActorType::Brick) {}

std::map<std::string, BrickFactory*> Brick::factories;

void Brick::RegisterFactoryType(const std::string& name, BrickFactory* factory)
{
	factories[name] = factory;
}

Brick* Brick::Create(const std::string& name)
{
	return factories[name]->Create();
}

ArmouredBrick::ArmouredBrick() : Brick()
{
	SetColor(sf::Color().Yellow);
}

ExplosiveBrick::ExplosiveBrick() : Brick()
{
	SetColor(sf::Color().Red);
}

void ExplosiveBrick::TakeDamage()
{
	std::cout << "Explosive taking damage" << std::endl;
	//sf::Vector2i index;
	//index.x = (int)(GetPosition().x / GetSize().x);
	//index.y = (int)(GetPosition().y / GetSize().y);
	//Game::GetBrickAtPosition(index.x, index.y - 1)->Destroy(); // Top
	//Game::GetBrickAtPosition(index.x, index.y + 1)->Destroy(); // Bottom
	//Game::GetBrickAtPosition(index.x - 1, index.y - 1)->Destroy(); // Top left
	//Game::GetBrickAtPosition(index.x - 1, index.y)->Destroy(); // Left
	//Game::GetBrickAtPosition(index.x - 1, index.y + 1)->Destroy(); // Bottom left
	//Game::GetBrickAtPosition(index.x + 1, index.y - 1)->Destroy(); // Top left
	//Game::GetBrickAtPosition(index.x + 1, index.y)->Destroy(); // Left
	//Game::GetBrickAtPosition(index.x + 1, index.y + 1)->Destroy(); // Bottom left
}

InvisibleBrick::InvisibleBrick() : Brick()
{
	SetColor(sf::Color().Black);
}

void InvisibleBrick::TakeDamage()
{
	std::cout << "Invisible taking damage" << std::endl;
	if (GetColor() == sf::Color().Black)
	{
		SetColor(visibleColor);
	}
	else
	{
		destroy = true;
	}
}

MetalBrick::MetalBrick() : Brick()
{
	SetColor(sf::Color().Blue);
}

void MetalBrick::TakeDamage()
{
	std::cout << "Metal taking damage" << std::endl;
	sf::Color color = GetColor();
	color.a -= alphaStep;
	SetColor(color);

	health--;
	if (health <= 0)
	{
		destroy = true;
	}
}

NormalBrick::NormalBrick() : Brick()
{
	SetColor(sf::Color().White);
}

void NormalBrick::TakeDamage()
{
	std::cout << "Normal taking damage" << std::endl;
	destroy = true;
}
