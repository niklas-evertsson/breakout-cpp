#pragma once
#include "Actor.h"

class Game
{
public:
	Game(sf::RenderWindow &window);
	
	void Tick();

protected:
	float DeltaTime();
	float ElapsedTime();
	void AddActor(Actor* actor);
	void CheckCollision(Actor* actor1, Actor* actor2);
	void Draw(Actor* actor);
	void LoadTextures();
	void Update(Actor* actor);

private:
	float deltaTime = 0.0f;
	float elapsedTime = 0.0f;
	sf::Clock deltaClock;
	sf::Clock elapsedClock;
	sf::RenderWindow &window;
	std::map<ActorType, sf::Texture> textures;
	std::vector<Actor*> actors;
};
