#include <iostream>
#include "Actor.h"

Actor::Actor(std::string imagePath)
{
	SetSprite(imagePath);
}

void Actor::SetSprite(std::string imagePath)
{
	sf::Texture texture;
	if (!texture.loadFromFile(imagePath))
	{
		std::cout << "Unable to open " << imagePath;
	}
	sprite.setTexture(texture);
}