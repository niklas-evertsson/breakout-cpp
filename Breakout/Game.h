#pragma once
#include "Actor.h"

class Game
{
public:
	Game(sf::RenderWindow &window);
	static sf::Texture& GetTexture(ActorType actorType);
	static Actor* GetBrickAtPosition(int x, int y) { return bricks[x][y]; }
	static Actor* GetBrickAtPosition(sf::Vector2i position) { return bricks[position.x][position.y]; }
	void Init();
	void Tick();

protected:
	float DeltaTime();
	float ElapsedTime();
	void AddActor(Actor* actor);
	void CheckCollision(Actor* actor1, Actor* actor2);
	void Draw(Actor* actor);
	void GenerateLevel();
	void LoadTextures();

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
