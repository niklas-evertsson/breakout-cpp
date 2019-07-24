#pragma once
#include "Actor.h"
#include "Command.h"
#include "UI.h"

class Game
{
public:
	Game(sf::RenderWindow &window);
	static sf::Texture& GetTexture(ActorType actorType);
	static Actor* GetBrickAtPosition(int col, int row);
	void ExecuteCommand(Command* command);
	void Init();
	void Tick();

protected:
	float DeltaTime();
	float ElapsedTime();
	void AddActor(Actor* actor);
	void CheckCollision();
	void ClearActors();
	void Draw();
	void EndGame();
	void GameOver();
	void GenerateLevel();
	void LoadTextures();
	void LosePlayerLife();
	void NewGame();
	void Update(Actor* actor);
	Actor* paddle = 0;
	UI* ui = 0;

private:
	float deltaTime = 0.0f;
	float elapsedTime = 0.0f;
	sf::Clock deltaClock;
	sf::Clock elapsedClock;
	sf::RenderWindow &window;
	std::vector<Actor*> actors;
	static std::map<ActorType, sf::Texture> textures;
	static std::vector<std::vector<Actor*>> bricks;
};
