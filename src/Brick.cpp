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

ExplosiveBrick::ExplosiveBrick() : Brick()
{
	name = "ExplosiveBrick";
	SetColor(sf::Color().Red);
}

void ExplosiveBrick::TakeDamage()
{
	if (!destroy)
	{
		GameData::AddScore(brickScore);
		destroy = true;
		sf::Vector2i index;
		index.x = (int)(GetPosition().x / GetSize().x);
		index.y = (int)(GetPosition().y / GetSize().y);
		std::vector<Actor*> bricks;
		bricks.push_back(Game::GetBrickAtPosition(index.x, index.y + 1)); // Bottom
		bricks.push_back(Game::GetBrickAtPosition(index.x - 1, index.y)); // Left
		bricks.push_back(Game::GetBrickAtPosition(index.x + 1, index.y)); // Right
		bricks.push_back(Game::GetBrickAtPosition(index.x, index.y - 1)); // Top
		bricks.push_back(Game::GetBrickAtPosition(index.x - 1, index.y + 1)); // Bottom left
		bricks.push_back(Game::GetBrickAtPosition(index.x + 1, index.y + 1)); // Bottom right
		bricks.push_back(Game::GetBrickAtPosition(index.x - 1, index.y - 1)); // Top left
		bricks.push_back(Game::GetBrickAtPosition(index.x + 1, index.y - 1)); // Top right
		std::vector<Actor*>::iterator it;
		for (it = bricks.begin(); it != bricks.end(); it++)
		{
			if (*it != NULL)
			{
				(*it)->Destroy();
				GameData::AddScore((int)(brickScore * 0.5f));
			}
		}
	}
}

MetalBrick::MetalBrick() : Brick()
{
	name = "MetalBrick";
	SetColor(sf::Color(255, 160, 0));
}

void MetalBrick::TakeDamage()
{
	sf::Color color = GetColor();
	color.a -= alphaStep > 0 ? alphaStep : 0;
	SetColor(color);

	health--;
	if (health <= 0)
	{
		GameData::AddScore(brickScore * 2);
		destroy = true;
	}
}

NormalBrick::NormalBrick() : Brick()
{
	name = "NormalBrick";
	SetColor(sf::Color().Yellow);
}

void NormalBrick::TakeDamage()
{
	GameData::AddScore(brickScore);
	destroy = true;
}
