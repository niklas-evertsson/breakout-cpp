#pragma once
#include "Actor.h"

class Ball : public Actor
{
public:
	Ball();

	void OnCollision(Actor& other);
	void Update(float deltaTime);

protected:
	float radius = 0.0f;
	sf::Color color = sf::Color().White;
	void WallCollision();
};
