#pragma once
#include <list>
#include "Actor.h"

class Game
{
public:
	Game();

	void AddActor(Actor* actor);
	void Draw(sf::RenderWindow &window);
	void Update(float deltaTime);

private:
	std::list<Actor*> actors;
};
