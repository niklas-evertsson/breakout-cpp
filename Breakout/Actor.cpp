#include <iostream>
#include "Actor.h"

Actor::Actor(std::string imagePath)
{
	SetSprite(imagePath);
}

void Actor::SetSprite(std::string imagePath)
{
	if (!texture.loadFromFile(imagePath))
	{
		std::cout << "Unable to load " << imagePath;
	}
	sprite.setTexture(texture);
}
