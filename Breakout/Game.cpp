#include "App.h"
#include "Brick.h"
#include "Ball.h"
#include "CSVReader.h"
#include "Game.h"
#include "GameData.h"
#include "Paddle.h"
#include <iostream>

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

void Game::CheckCollision()
{
	std::vector<Actor*>::iterator it1;
	std::vector<Actor*>::iterator it2;
	for (it1 = actors.begin(); it1 != actors.end(); it1++)
	{
		for (it2 = actors.begin(); it2 < it1; it2++)
		{
			if (!*it1)
			{
				continue;
			}
			if (!*it2)
			{
				continue;
			}
			sf::FloatRect box1 = (*it1)->GetGlobalBounds();
			sf::FloatRect box2 = (*it2)->GetGlobalBounds();

			if (box1.intersects(box2))
			{
				(*it1)->OnCollision(**it2);
				(*it2)->OnCollision(**it1);
			}
		}
	}
}

void Game::ClearActors()
{
	std::vector<Actor*>::iterator it;
	for(it = actors.begin(); it != actors.end(); it++)
	{
		delete* it;
		*it = 0;
	}
	actors.clear();
}

void Game::Draw()
{
	std::vector<Actor*>::iterator it;
	for(it = actors.begin(); it != actors.end(); it++)
	{
		window.draw(*(*it)->GetSprite());
	}
}

void Game::ExecuteCommand(Command* command)
{
	if(command)
	{
		command->Execute(paddle);
	}
}

void Game::GameOver()
{
	GameData::SetState(GameState::waitingForStart);
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
	ui = new UI(window);
	LoadTextures();
	NewGame();
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

void Game::LosePlayerLife()
{
	PlayerData::LoseLife();
	if (PlayerData::GetLives() <= 0)
	{
		GameOver();
	}
	else
	{
		GameData::SetState(GameState::betweenGames);
		Actor* ball = new Ball();
		AddActor(ball);
	}
}

void Game::NewGame()
{
	ClearActors();
	GenerateLevel();
	paddle = new Paddle();
	AddActor(paddle);
	Actor* ball = new Ball();
	AddActor(ball);
}

void Game::Tick()
{
	std::cout << GameData::GetState() << std::endl;
	deltaTime = DeltaTime();
	elapsedTime = ElapsedTime();
	if (GameData::GetState() == GameState::starting)
	{
		PlayerData::ResetLives();
		NewGame();
		GameData::SetState(GameState::playing);
	}
	if (GameData::GetState() == GameState::playing)
	{
		CheckCollision();
		std::vector<Actor*>::iterator it;
		bool ballInPlay = false;
		for(it = actors.begin(); it != actors.end(); it++)
		{
			if ((*it)->GetType() == ActorType::Ball)
			{
				ballInPlay = true;
			}
			Update(*it);

			if ((*it)->GetDestroy())
			{
				delete *it;
				it = actors.erase(it);
				it--;
			}
		}
		if (!ballInPlay)
		{
			LosePlayerLife();
		}
	}
	Draw();
	ui->Draw();
}

void Game::Update(Actor* actor)
{
	actor->Update(deltaTime);
}
