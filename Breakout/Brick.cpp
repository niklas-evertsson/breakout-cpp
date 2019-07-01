#include "Brick.h"
#include "Game.h"

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
	name = "ArmouredBrick";
	SetColor(sf::Color().Yellow);
}

ExplosiveBrick::ExplosiveBrick() : Brick()
{
	name = "ExplosiveBrick";
	SetColor(sf::Color().Red);
}

void ExplosiveBrick::TakeDamage()
{
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
	name = "InvisibleBrick";
	SetColor(sf::Color().Black);
}

void InvisibleBrick::TakeDamage()
{
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
	name = "MetalBrick";
	SetColor(sf::Color().Blue);
}

void MetalBrick::TakeDamage()
{
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
	name = "NormalBrick";
	SetColor(sf::Color().White);
}

void NormalBrick::TakeDamage()
{
	destroy = true;
}
