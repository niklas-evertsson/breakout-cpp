#pragma once
#include "Actor.h"

class Paddle : public Actor
{
public:
	Paddle();

protected:
	sf::Color color = sf::Color().White;
};

