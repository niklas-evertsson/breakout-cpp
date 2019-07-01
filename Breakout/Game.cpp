#include "App.h"
#include "Brick.h"
#include "Ball.h"
#include "CSVReader.h"
#include "Game.h"

Game::Game(sf::RenderWindow& window) : window(window) {}

std::map<ActorType, sf::Texture> Game::textures;
std::vector<std::vector<Actor*>> Game::bricks;

float Game::DeltaTime()
{
	return deltaClock.restart().asSeconds();
}

float Game::ElapsedTime()
{
	return elapsedClock.getElapsedTime().asSeconds();
}

sf::Texture& Game::GetTexture(ActorType actorType)
{
	return textures[actorType];
}

void Game::AddActor(Actor* actor)
{
	actors.push_back(actor);
}

void Game::CheckCollision(Actor* actor1, Actor* actor2)
{
	sf::FloatRect box1 = actor1->GetGlobalBounds();
	sf::FloatRect box2 = actor2->GetGlobalBounds();

	if (box1.intersects(box2))
	{
		actor1->OnCollision(*actor2);
		actor2->OnCollision(*actor1);
	}
}

void Game::Draw(Actor* actor)
{
	window.draw(*(actor)->GetSprite());
}

void Game::GenerateLevel()
{
	sf::Vector2i index;
	sf::Vector2i resolution = App::GetResolution();
	sf::Vector2u brickSize = textures[ActorType::Brick].getSize();
	std::vector<std::vector<std::string>> layout = CSVReader::Read(App::GetLevelPath());
	bricks.resize(layout.size());
	std::vector<std::vector<Actor*>>::iterator it0;
	for(it0 = bricks.begin(); it0 != bricks.end(); it0++)
	{
		it0->resize(layout.at(0).size());
	}
	std::vector<std::vector<std::string>>::iterator it1;
	std::vector<std::string>::iterator it2;
	for (it1 = layout.begin(); it1 != layout.end(); it1++)
	{
		for (it2 = it1->begin(); it2 != it1->end(); it2++)
		{
			if (*it2 != "")
			{
				Actor* brick = Brick::Create(*it2);
				bricks.at(index.y).at(index.x) = brick;
				brick->SetPosition((float)index.x * brickSize.x, (float)index.y * brickSize.y);
				AddActor(brick);
			}
			index.x++;
		}
		index.x = 0;
		index.y++;
	}
}

void Game::Init()
{
	LoadTextures();
	GenerateLevel();
	Actor* ball = new Ball();
	AddActor(ball);
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
		textures.insert(std::make_pair(it->first, texture));
	}

}

void Game::Tick()
{
	deltaTime = DeltaTime();
	elapsedTime = ElapsedTime();

	std::vector<Actor*>::iterator it1;
	std::vector<Actor*>::iterator it2;
	for(it1 = actors.begin(); it1 != actors.end(); it1++)
	{
		(*it1)->Update(deltaTime);
		Draw(*it1);
		if ((*it1)->GetDestroy())
		{
			it1 = actors.erase(it1);
			it1--;
		}

		for(it2 = actors.begin(); it2 < it1; it2++)
		{
			CheckCollision(*it1, *it2);
		}
	}
}
